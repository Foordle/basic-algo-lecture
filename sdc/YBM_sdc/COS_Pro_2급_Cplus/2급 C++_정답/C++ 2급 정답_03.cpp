#include <iostream>
#include <vector>
using namespace std;

const int RED = 1;
const int BLUE = 2;
const int GRAY = 3;

int solution(int N, int M, vector<vector<int>> area, int C) {
	int answer = 0;

	vector<vector<int>> paper(N, vector<int>(N));

	for (int i = 0; i < M; i++) {
		vector<int> target = area[i];

		int from_r = target[0];
		int from_c = target[1];
		int to_r = target[2];
		int to_c = target[3];
		int color = target[4];

		for (int r = from_r; r <= to_r; r++) {
			for (int c = from_c; c <= to_c; c++) {
				if (paper[r][c] == 0) {
					paper[r][c] = color;
				}
				else if(paper[r][c] != color){
					paper[r][c] = GRAY;
				}
			}
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (C == paper[r][c]) {
				answer += 1;
			}
		}
	}

	return answer;

}