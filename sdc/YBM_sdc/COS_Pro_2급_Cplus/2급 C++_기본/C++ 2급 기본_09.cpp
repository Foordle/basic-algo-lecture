#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr, int N, int J) {
    // 여기에 코드를 작성해 주세요
    int answer = 0;
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.

int main() {    
    
	vector<int> arr1 = {7, 5, 2, 9, 3, 4};
	int N1 = 6;
	int J1 = 80;
	int ret1 = solution(arr1, N1, J1);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<int> arr2 = {4, 11, 6, 5, 7, 1, 2, 9, 15};
	int N2 = 9;
	int J2 = 444;
	int ret2 = solution(arr2, N2, J2);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;

	vector<int> arr3 = {1, 3, 1, 3, 1};
	int N3 = 5;
	int J3 = 131;
	int ret3 = solution(arr3, N3, J3);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret3 << " 입니다." << endl;

}
