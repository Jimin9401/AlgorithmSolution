

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>


int **make2array(int col, int row) {

	int **arr;

	arr = (int**)calloc(row, sizeof(int *));


	for (int j = 0; j < row; j++) {
		arr[j] = (int*)calloc(col, sizeof(int));
	}

	return arr;
}




int main() {

	int col, row;

	int **arr;
	
	scanf("%d %d", &col, &row);

	arr = make2array(col, row);
	

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::printf("%3d", arr[i][j]);
		}
		std::printf("\n");
	}
	std::printf("\n");


	return 0;
}
