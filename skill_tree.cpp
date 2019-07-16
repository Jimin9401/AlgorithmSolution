// https://programmers.co.kr/learn/courses/30/lessons/49993
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

int BFS(vector<vector<int>> maps, int **boolarr) {

	vector<int>a = q.front();

	int x = a.at(0);
	int y = a.at(1);
	int d = a.at(2);


	boolarr[0][0] = 1;

	while (!q.empty()) {
		a = q.front();


		x = a.at(0);
		y = a.at(1);
		d = a.at(2);


		if (x == maps.size() - 1 && y == maps.at(0).size() - 1) {

			printf("%d", d);
			return d;

		}

		if (x + 1 < maps.size() && maps[x + 1][y] == 1 && boolarr[x + 1][y] == 0) {
			boolarr[x + 1][y] = 1;
			q.push({ x + 1, y,d + 1 });
		}
		if (y + 1 < maps.at(0).size() && maps[x][y + 1] == 1 && boolarr[x][y + 1] == 0) {
			boolarr[x][y + 1] = 1;
			q.push({ x , y + 1,d + 1 });
		}
		if (x - 1 >= 0 && maps[x - 1][y] == 1 && boolarr[x - 1][y] == 0) {
			boolarr[x - 1][y] = 1;
			q.push({ x - 1, y,d + 1 });
		}
		if (y - 1 >= 0 && maps[x][y - 1] == 1 && boolarr[x][y - 1] == 0) {
			boolarr[x][y - 1] = 1;
			q.push({ x, y - 1,d + 1 });
		}

		/*for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				printf("%d ", boolarr[i][j]);
			}
			printf("\n");
		}
*/
		q.pop();

	}



	printf("%d", -1);

	return -1;

}

int solution(vector<vector<int>> maps) {

	vector<int> v1 = { 0,0,1 };

	q.push(v1);

	int **boolarr;
	boolarr = (int**)calloc(sizeof(int*), maps.size());

	for (int i = 0; i < maps.size(); i++) {
		boolarr[i] = (int*)calloc(sizeof(int), maps.at(0).size());
	}

	int answer = BFS(maps, boolarr);

	return answer;

}
int main()
{
	
	vector<vector<int>> maze;
	int n;
	int value;

	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> tmp_maze;
		for (int i = 0; i < n; i++) {
			cin >> value;
			tmp_maze.push_back(value);
		}
		maze.push_back(tmp_maze);
	}

	solution(maze);

	return 0;
}
