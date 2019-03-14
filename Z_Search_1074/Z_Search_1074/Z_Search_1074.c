/*
	���� �˰��� ���� Ǯ�� 1074�� (Recursion Example)
	Z Ž�� : https://www.acmicpc.net/problem/1074

	*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int z_search(int N, int r, int c) {

	int dim = pow(2, N);

	if (N == 0) {
		return 0;
	}
	else {
		if (r < dim / 2) {
			if (c < dim / 2) {
				return 0 * pow(2,2*N-2) + z_search(N - 1, r, c); // 0��°
			}
			else {
				return 1 * pow(2, 2 * N - 2) + z_search(N - 1, r , c - dim / 2); // 1��°
			}
		}
		else {
			if (c < dim / 2) {
				return 2 * pow(2, 2 * N - 2) + z_search(N - 1, r - dim / 2, c ); // 2��°
			}
			else {
				return 3 * pow(2, 2 * N - 2) + z_search(N - 1, r - dim / 2, c - dim / 2); // 3��°
			}
		}
	}



}



int main()
{
	int N, r, c;

	scanf("%d %d %d", &N, &r, &c);


	printf("%d", z_search(N, r, c));



	return 0;
}
