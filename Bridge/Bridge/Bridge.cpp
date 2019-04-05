// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#define max_size (100)

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <stdio.h>




typedef int element;

typedef struct AQueue {
	element top;
	element rear;
	element *contents;
}AQueue;

int is_full(AQueue *q){
	
	return (q->top == (q->rear + 1) % max_size);
}


AQueue create() {
	AQueue *queue;
	queue = (AQueue*)malloc(sizeof(AQueue));
	queue->contents= (element*)malloc(sizeof(element)*max_size);
	queue->top = 0;
	queue->rear = 0;

	return *queue;
}

void push(AQueue *q,element i) {
	if (is_full(q)) {
		printf("Error: already Full");
	}
	else {
		q->rear++;
		q->contents[q->rear%max_size] = i;
	}
}

element pop(AQueue *q) {
	element tmp;
	tmp = q->contents[(q->top+1 )% max_size];
	q->top++;
	return tmp;
}


element peek(AQueue *q) {
	element tmp;
	tmp = q->contents[(q->top + 1) % max_size];
	return tmp;
}

void printQ(AQueue *q) {
	
	for (int i = q->top + 1; i <= q->rear; i++) {
		printf("%d ", q->contents[i%max_size]);
	}
	printf("\n");
}

element sumTruck(AQueue *q) {
	element sum = 0;
	for (int i = q->top + 1; i <= q->rear; i++) {
		sum += q->contents[i];
	}
	return sum;
}

void plustime(AQueue *q) {

	for (int i = q->top + 1; i <= q->rear; i++) {
		q->contents[i]++;
	}
}


int main()
{
	element max_weight;
	element numTruck;
	element *arr;
	element sec = 0;
	element through;

	printf("number of truck: ");
	scanf("%d", &numTruck);
	printf("bridge length: ");
	scanf("%d", &through);
	printf("max weight: ");
	scanf("%d", &max_weight);


	arr = (element*)malloc(sizeof(element)*numTruck);
	
	AQueue onbridge, waiting, timearr;
	onbridge = create();
	waiting = create();
	timearr = create();

	printf("Insert trucks' weight: ");

	for (int i = 0; i < numTruck; i++) {
		scanf("%d", &arr[i]);
		push(&waiting, arr[i]);
	}

	push(&onbridge, pop(&waiting));
	push(&timearr, 1);
	sec++;

	while (onbridge.rear != (onbridge.top) && waiting.top!=waiting.rear) 
	{
		if (peek(&timearr) == through) {
			pop(&timearr);
			pop(&onbridge);
		}
		
		if (waiting.top == (waiting.rear)) 
		{
		
//			if (sumTruck(&onbridge) <= max_weight) {
				plustime(&timearr);
			//	push(&onbridge, pop(&waiting));
			//	push(&timearr, 1);
				sec++;
//			}
		}	
		else {
			if (sumTruck(&onbridge) + peek(&waiting) <= max_weight) 
			{
					plustime(&timearr);
					push(&onbridge, pop(&waiting));
					push(&timearr, 1);
					sec++;
			}
			else if(sumTruck(&onbridge)<=max_weight)
			{
					plustime(&timearr);
					sec++;
			}
		}
	}


	

	printf("\n%d\n", sec);

	return 0;
}
