#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



void num(int n,int *arr) {

	if (n > 0) {
		num(n - 1,arr);
		if (n < 10) {
			arr[n%10]+=1;
		}
		else {
			num(n / 10,arr);
			arr[n%10]+=1;
		}
	}
}

int main()
{
	int number;
	int arr[10];

	scanf("%d", &number);

	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}

	num(number, arr);

	for (int i = 0; i < 10; i++) {
		printf("%d ",arr[i]);
	}

	return 0;
}