#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> arr) {
	int N = 10;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				int length = 0;

				for (int w = 2; w < 11; w++) {
					bool is_square = true;

					for (int di = i; di < i + w; di++) {
						for (int dj = j; dj < j + w; dj++) {
							if (di >= N || dj >= N || arr[di][dj] == 0) {
								is_square = false;
								break;
							}
						}
						if (!is_square) {
							break;
						}
					}

					if (is_square) {
						length = w;
					}
					else {
						break;
					}
				}

				if (length > 1) {
					for (int di = i; di < i + length; di++) {
						for (int dj = j; dj < j + length; dj++) {
							arr[di][dj] = 0;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				return 0;
			}
		}
	}

	return 1;
}