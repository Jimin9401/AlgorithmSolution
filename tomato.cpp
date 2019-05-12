// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<queue>
#include<stdlib.h>



using namespace std;

int **make2array(int col, int row) {

	int **arr;

	arr = (int**)calloc(row, sizeof(int *));


	for (int j = 0; j < row; j++) {
		arr[j] = (int*)calloc(col, sizeof(int));
	}
	return arr;
}

int main()
{
	int row, col;
	scanf("%d %d", &col, &row);

	queue<pair<int, int>> Q;

	queue<pair<int, int>> stepQ;

	int **arr = make2array(col, row);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int empty = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1) {
				Q.push(make_pair(i, j));

			}
			if (arr[i][j] == 0) {
				empty++;
			}
		}
	}
	pair<int, int> tmp;

	int area = 0;
	int answer = 0;
	stepQ.push(Q.back());
	while (!(Q.empty())) {
		tmp = Q.front();
		int x = tmp.first;
		int y = tmp.second;

		if (x >= 1) {
			if (arr[x - 1][y] == 0) {
				arr[x - 1][y] = 1;
				Q.push(make_pair(x - 1, y));
				area++;
			}
		}
		if (y >= 1) {
			if (arr[x][y - 1] == 0) {
				arr[x][y - 1] = 1;
				Q.push(make_pair(x, y - 1));
				area++;
			}
		}
		if (x < row - 1) {
			if (arr[x + 1][y] == 0) {
				arr[x + 1][y] = 1;
				Q.push(make_pair(x + 1, y));
				area++;
			}
		}
		if (y < col - 1) {
			if (arr[x][y + 1] == 0) {
				arr[x][y + 1] = 1;
				Q.push(make_pair(x, y + 1));
				area++;
			}
		}
		if (Q.size() == 0 && area < empty) {
			answer = -1;
		}
		else if (area == empty) {
			answer = stepQ.size();
		}
			if (stepQ.back() == tmp) {
				stepQ.push(Q.back());
			}
			Q.pop();
	}
	printf("%d", answer-1);
	return 0;
}
