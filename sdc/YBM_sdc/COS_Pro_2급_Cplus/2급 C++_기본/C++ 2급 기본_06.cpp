#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr, int N) {
	int frequency[101] = { 0 };

	for (int i = 0; i < N; i++) {
		[[quiz]] += 1;
	}

	int best = 0;
	int num = 0;

	for (int i = 0; [[quiz]]; i++) {
		if (best <= frequency[i]) {
			best = frequency[i];
			if ([[quiz]]) {
				[[quiz]];
			}
		}
	}

	return num;
}

int main() {    
    
	vector<int> arr1 = {1,2,3,4,4,5,6,7,7,8,9,9,9,9,10};
	int N1 = 15;
	int ret1 = solution(arr1, N1);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<int> arr2 = {1,1,4,4,8,8,8,8,9,9,9,9,1,4,4,4,5,3,2,2,1,4,8,7};
	int N2 = 24;
	int ret2 = solution(arr2, N2);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;

	vector<int> arr3 = {3,3,3,3,3,5,5,5,5,5,9,9,9,9,9,11,11,11,11,11};
	int N3 = 20;
	int ret3 = solution(arr3, N3);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret3 << " 입니다." << endl;

}
