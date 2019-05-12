// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <stdio.h>
#include<stdlib.h>
#include<queue>



using namespace std;

int **make2array(int i) {
	
	int **arr;

	arr = (int**)calloc(i, sizeof(int *));


	for (int j = 0; j < i; j++) {
		arr[j] = (int*)calloc(i, sizeof(int));
	}

	return arr;
}


int main()
{
	queue<int> Q;

	int number, n, a,b;

	scanf("%d", &number);

	scanf("%d", &n);

	int **arr;
	int *boolarr;

	arr = make2array(number);
	boolarr = (int*)calloc(number,sizeof(int));

	for (int k = 0; k < n; k++) {
		scanf("%d %d", &a, &b);
		arr[a-1][b-1] = 1;
		arr[b - 1][a - 1] = 1;
	}

	int initial= 0;
	int cnt = 0;

	Q.push(initial);


	boolarr[0] = 1;
	while (Q.size()!=0) {	
		for (int i = 0; i < number; i++) {
			if (arr[initial][i] == 1 && boolarr[i]!=1) 
			{
				Q.push(i);
				boolarr[i] = 1;
				cnt++;
			}
		}
		Q.pop();
		if (Q.size() != 0) {
			initial = Q.front();
		}
	}

	printf("%d", cnt);


	return 0;
}
