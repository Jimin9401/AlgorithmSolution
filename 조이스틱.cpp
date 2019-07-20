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

vector<int> alphabets;


int search_direction(int start_pt,int *answer) {
	
	*answer += alphabets.at(start_pt);
	alphabets.at(start_pt) = 0;
//	printf("\n");

	//for (int i : alphabets) {
	//	printf("%d ", i);
	//}

	int left=(alphabets.size()+start_pt-1)%alphabets.size();
	int right= (start_pt+1)%alphabets.size();

	int move_left = 1;
	int move_right = 1;

	while (alphabets.at(left)==0 && left != start_pt){
		
		left = (alphabets.size() + left - 1) % alphabets.size();
		
		move_left++;
	}

	while (alphabets.at(right) ==0 && right!=start_pt) {
		right = (right + 1) % alphabets.size();

		move_right++;
	}

	if (start_pt == left && start_pt == right) {
		return -1;
	}



	if (move_left >= move_right) {
		*answer += move_right;
		return right;
	}
	else {
		*answer += move_left;
		return left;
	}



}


int solution(string name) {
	int answer = 0;

	for (char a : name) {
		if (a - 'A' <= 'Z' - a+1) {
			alphabets.push_back(a - 'A');
		}
		else {
			alphabets.push_back('Z' - a+1);
		}

	}

	int start_pt = 0;

	//for (int i : alphabets) {
	//	printf("%d ", i);
	//}

	while (start_pt != -1) {
		start_pt = search_direction(start_pt, &answer);
	}


	//for (int i : alphabets) {
	//	printf("%d ", i);
	//}


	printf("%d", answer);

	return answer;


}


int main()
{
	string number;


	cin >> number;

	solution(number);

	return 0;
}