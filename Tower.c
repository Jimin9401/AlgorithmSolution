/*

	resource: https://programmers.co.kr/learn/courses/30/lessons/42588 

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef int Item;
//의도.. 저장되는 데이터 타입이 바뀔 수도 있으니!


typedef struct Stack_t {
	Item *contents; // 배열내에 들어가는 콘텐츠
	int size; // 스택의 사이즈
	int top; //스택에 가장 위
} *Stack;



Stack create() {
	Stack s;
	s = (Stack)malloc(sizeof(Stack));
	s->contents = (Item*)malloc(sizeof(Item));
	s->size = 100;
	s->top = -1;
	return s;
}

void is_empty(Stack s) {
	if (s->top == -1) {
		printf("Empty!\n");
	}
	else {
		printf("Not Empty!\n");
	}
}

void is_full(Stack s) {
	if (s->top == s->size) {
		printf("Full!\n");
	}
	else
		printf("Not Full!\n");
}

void push(Stack s, Item i) {
	s->top++;
	s->contents[s->top] = i;
}

Item pop(Stack s) {
	Item tmp;
	tmp = s->contents[s->top];
	s->top--;
	return tmp;
}

Item peek(Stack s) {
	Item tmp;
	tmp = s->contents[s->top];

	return tmp;
}

void printStack(Stack s) {

	for (int i = 0; i <= s->top; i++) {
		printf("%d ", s->contents[i]);
	}
	printf("\n");
}

int main()
{
	Stack s = create();
	Stack h = create();

	int *height;
	int *arr;
	int *solution;
	int size;
//	Item a;

	scanf("%d", &size);
	height = (int*)malloc(sizeof(int)*size);
	solution = (int*)malloc(sizeof(int)*size);

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &height[i]);
		push(s, height[i]);
	}

	for (int i = 0; i < size; i++) {
		solution[i] = 0;
	}
	
	while (s->top != -1) {
		
		push(h, pop(s));

		int ix = h->top;
		
		int sol_ix = 0;
		
		while(ix!=-1)
		{
			if ((h->contents)[ix] < peek(s)) 
			{
				if (solution[(s->top) + 1 + sol_ix] == 0) {
					solution[(s->top) + 1 + sol_ix] = (s->top)+1 ;
				}

			}
			sol_ix++;
			ix--;
		}
	}
	


	printf("  ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", solution[i]);
	}

	getchar();
	return 0;
}
