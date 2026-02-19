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
		for (int j = 1; j < can[2]; j++) {
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

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.

int main() {    
    
	vector<vector<int>> watering_can1 = {{2,2,2},{0,0,1}};
	int N1 = 5;
	int M1 = 2;
	int ret1 = solution(watering_can1, N1, M1);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

}
