// https://programmers.co.kr/learn/courses/30/lessons/1845
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


queue<vector<int>> q;
using namespace std;


queue<vector<int>> q;
int solution(vector<int> nums)
{
	unordered_map<int, int> h;
	int answer = 0;

	int tri = nums.size() / 2;

	for (int n : nums) {
		h[n]++;
	}

	if (tri < h.size()) {
		answer = tri;
	}
	else {
		answer = h.size();
	}
	return answer;
}
int main()
{
	vector<int> nums;
	int value;
	for (int i = 0; i < n; i++) {
		cin >> value;
		nums.push_back(value);
	}

	solution(nums);

	return 0;
}
