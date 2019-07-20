// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

int test(int i,int j,int *arr) {
	while (arr[i] >= 0) {
		i = arr[i];
	}
	while (arr[j] >= 0) {
		j = arr[j];
	}

	if (i == j) {
		return 1;
	}
	
	else {
		arr[j] += arr[i];
		arr[i] = j;
		return 0;
	}

}

int compare(vector<int> a, vector<int> b) {
	return a.at(2) < b.at(2);
}



int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int **arr;
	arr = (int**)calloc(sizeof(int*), n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)calloc(sizeof(int), n);
	}

	int *vertex = (int*)calloc(sizeof(int*), n);
	
	for (int i = 0; i < n; i++) {
		vertex[i] = -1;
	}

	int connect = 0;

	//for (auto c : costs) {
	//	printf("%d %d %d\n", c.at(0), c.at(1), c.at(2));
	//}
	
	//printf("\n");

	sort(costs.begin(), costs.end(),compare);

	//for (auto c : costs) {
	//	printf("%d %d %d\n", c.at(0), c.at(1), c.at(2));
	//}


	for (auto c : costs) {
		if (test(c.at(0), c.at(1),vertex)==0) {
			answer += c.at(2);
			connect++;
		}
		if (connect == n - 1) {
			break;
		}
	}



	//printf("%d", answer);

	return answer;
}


int main()
{

	int edge_cnt;

	int n;
	vector<vector<int>> costs;
	int value;
	cin >> edge_cnt;
	cin >> n;

	for (int i = 0; i < edge_cnt; i++) {
		vector<int> tmp;
		
		for (int i = 0; i < 3; i++) {
			cin >> value;
			tmp.push_back(value);
		}
		
		costs.push_back(tmp);
	}


	solution(n, costs);

	return 0;
}
