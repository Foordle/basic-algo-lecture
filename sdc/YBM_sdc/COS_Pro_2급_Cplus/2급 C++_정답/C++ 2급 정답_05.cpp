#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board) {
	int min_avg = 100;
	int max_avg = 0;

	for (int i = 0; i < 5; i++) {
		int sum_x = 0;
		int sum_y = 0;
		for (int j = 0; j < 5; j++) {
			sum_x += board[i][j];
			sum_y += board[j][i];
		}

		sum_x /= 5;
		sum_y /= 5;

		if (max_avg < sum_x) {
			max_avg = sum_x;
		}
		if (max_avg < sum_y) {
			max_avg = sum_y;
		}
		if (min_avg > sum_x) {
			min_avg = sum_x;
		}
		if (min_avg > sum_y) {
			min_avg = sum_y;
		}

	}

	int sum_d1 = 0;
	int sum_d2 = 0;

	for (int i = 0; i < 5; i++) {
		sum_d1 += board[i][i];
		sum_d2 += board[i][4 - i];
	}

	sum_d1 /= 5;
	sum_d2 /= 5;

	if (max_avg < sum_d1) {
		max_avg = sum_d1;
	}
	if (max_avg < sum_d2) {
		max_avg = sum_d2;
	}
	if (min_avg > sum_d1) {
		min_avg = sum_d1;
	}
	if (min_avg > sum_d2) {
		min_avg = sum_d2;
	}

	return min_avg + max_avg;
}