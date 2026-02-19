#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr, int N, int M) {
	int min_sum = 50000;
	int max_sum = 0;

	for (int i = 0; i < N - M + 1; i++) {
		int temp_max = 0;
		for (int j = i; j < i + M; j++) {
			temp_max += arr[j];
		}
		if (temp_max > [[quiz]]) {
			[[quiz]] = temp_max;
		}
		if (temp_max < [[quiz]]) {
			[[quiz]] = temp_max;
		}
	}

	return max_sum - min_sum;
}

int main() {    
    
	vector<int> arr1 = {3,1,1,4,5,9};
	int N1 = 6;
	int M1 = 3;
	int ret1 = solution(arr1, N1, M1);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<int> arr2 = {3,1,1,4,5,9};
	int N2 = 6;
	int M2 = 2;
	int ret2 = solution(arr2, N2, M2);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;

	vector<int> arr3 = {1,2,3,4,5,6};
	int N3 = 6;
	int M3 = 4;
	int ret3 = solution(arr3, N3, M3);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret3 << " 입니다." << endl;

}
