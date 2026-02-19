#include <iostream>
#include <vector>
using namespace std;

const int NO_WATER = 0;
const int WATER = 1;

int solution(vector<vector<int>>watering_can, int N, int M) {
	int answer = 0;

	vector<vector<int>> garden(N, vector<int>(N));

	for (int i = 0; i < M; i++) {
		vector<int> can = watering_can[i];
		garden[can[0]][can[1]] = WATER;
		for (int j = 1; j < can[2] + 1; j++) {
			if (can[0] + j < N) {
				garden[can[0] + j][can[1]] = WATER;
			}
			if (can[0] - j >= 0) {
				garden[can[0] - j][can[1]] = WATER;
			}
			if (can[1] + j < N) {
				garden[can[0]][can[1] + j] = WATER;
			}
			if (can[1] - j >= 0) {
				garden[can[0]][can[1] - j] = WATER;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (garden[i][j] == NO_WATER) {
				answer += 1;
			}
		}
	}

	return answer;
}