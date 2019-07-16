/*
	백준 알고리즘 4811번
	알약 문제: https://www.acmicpc.net/problem/4811 (recursion)
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int medicine(int w, int h) {

	if (w == 0) {
		return 1;
	}
	else {
		if (h == 0) {
			return medicine(w - 1, h + 1);
		}
		else {
			return medicine(w - 1, h + 1) + medicine(w, h - 1);
		}
	}

}

int main()
{
	int n;

	scanf("%d", &n);

	int w = n;
	int h = 0;

	printf("%d",medicine(w, h));



	return 0;
}
