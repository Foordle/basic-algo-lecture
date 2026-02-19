#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> arr, int N) {
    // 여기에 코드를 작성해 주세요
    int answer = 0;
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.

int main() {    
    
	vector<vector<int>> arr1 = {{0, 25, 7, 56, 12}, {4, 0, 31, 88, 45}, {62, 19, 0, 71, 23}, {95, 36, 51, 0, 44}, {16, 41, 66, 73, 0}};
	int N1 = 5;
	int ret1 = solution(arr1, N1);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<vector<int>> arr2 = {{0, 11, 24, 98, 46}, {53, 0, 29, 62, 75}, {82, 36, 0, 5, 18}, {42, 54, 33, 0, 21}, {9, 54, 92, 86, 0}};
	int N2 = 5;
	int ret2 = solution(arr2, N2);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;

	vector<vector<int>> arr3 = {{0, 18, 34, 22}, {48, 0, 55, 61}, {18, 7, 0, 15}, {71, 86, 94, 0}};
	int N3 = 4;
	int ret3 = solution(arr3, N3);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret3 << " 입니다." << endl;

}
