#include <iostream>
#include <vector>
using namespace std;

int min_value;
vector<vector<int>> rooms;
vector<int> visited;
int length;

void patrol(int now, int e_sum) {
	if (e_sum < min_value) {

		bool zero = false;

		for (int i = 0; i < visited.size(); i++) {
			if (visited[i] == 0) {
				zero = true;
			}
		}

		if (!zero) {
			min_value = min(min_value, e_sum + rooms[now][0]);
		}
	}

	for (int i = 0; i < length; i++) {
		if (i != now && visited[i] == 0) {
			visited[i] = 1;
			patrol(i, e_sum + rooms[now][i]);
			visited[i] = 0;
		}
	}
}

int solution(vector<vector<int>> arr, int N) {
	visited.resize(N, 0);
	visited[0] = 1;
	length = N;
	rooms = arr;
	min_value = 10000;
	patrol(0, 0);

	return min_value;
}