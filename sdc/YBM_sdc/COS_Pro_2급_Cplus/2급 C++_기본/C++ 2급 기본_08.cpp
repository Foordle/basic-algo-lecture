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

					for (int di = i; di < [[quiz]]; di++) {
						for (int dj = j; dj < [[quiz]]; dj++) {
							if ([[quiz]]) {
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
					for (int di = i; di < [[quiz]]; di++) {
						for (int dj = j; dj < [[quiz]]; dj++) {
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

int main() {    
    
	vector<vector<int>> arr1 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},  {0, 0, 1, 1, 1, 0, 1, 1, 1, 1},  {0, 0, 1, 1, 1, 0, 1, 1, 1, 1},  {0, 0, 1, 1, 1, 0, 1, 1, 1, 1},  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};
	int ret1 = solution(arr1);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<vector<int>> arr2 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},  {0, 1, 1, 1, 1, 1, 0, 1, 1, 1},  {0, 1, 1, 1, 1, 1, 0, 1, 1, 1},  {0, 1, 1, 1, 1, 1, 0, 1, 1, 1},  {0, 1, 1, 1, 1, 1, 0, 1, 1, 1},  {0, 1, 1, 1, 1, 1, 0, 1, 1, 1},  {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},  {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	int ret2 = solution(arr2);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;

	vector<vector<int>> arr3 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 0, 0, 1, 1}, {0, 1, 1, 1, 1, 1, 0, 0, 1, 1}, {0, 1, 1, 1, 1, 1, 0, 0, 0, 0}, {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}};
	int ret3 = solution(arr3);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret3 << " 입니다." << endl;

}
