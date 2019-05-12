// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

int recursiveminus(int sum, vector<int> Q, int target);
int recursiveplus(int sum, vector<int> Q, int target);

int recursiveminus(int sum, vector<int> Q, int target) {
	sum -= Q.back();

	if (Q.size() > 1) {
		Q.pop_back();
		return recursiveplus(sum, Q, target) + recursiveminus(sum, Q, target);
	}
	else if (Q.size() == 1 && sum == target) {
		return 1;
	}
	else if (Q.size() == 1 && sum != target) {

		return 0;
	}
}


int recursiveplus(int sum, vector<int> Q, int target) {
	sum += Q.back();
	if (Q.size() > 1) {
		Q.pop_back();
		return recursiveplus(sum, Q, target) + recursiveminus(sum, Q, target);
	}
	else if (Q.size() == 1 && sum == target) {
		return 1;
	}
	else if (Q.size() == 1 && sum != target) {
		return 0;
	}

}

int solution(vector<int>numbers, int  target) {
	int answer = recursiveplus(0, numbers, target) + recursiveminus(0, numbers, target);
	return answer;
}

int main()
{
	vector<int> Q;
	int number, target;

	scanf("%d", &number);

	scanf("%d", &target);

	int *arr;

	arr = (int*)calloc(sizeof(int), number);

	for (int i = 0; i < number; i++)
	{
		scanf("%d", &arr[i]);
		Q.push_back(arr[i]);
	}


	int answer;

	answer = solution(Q, target);


	printf("%d\n", answer);

	return 0;
}
