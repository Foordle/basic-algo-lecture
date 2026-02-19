// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int numberA, int numberB, int limit) {
    // 여기에 코드를 작성해주세요.
	bool nums[1001] = {false};
	nums[0] = true;
	for (int i = 1; i <= limit; i++) {
		if (i - numberA >= 0 && nums[i - numberA]) {
			nums[i] = true;
		}
		if (i - numberB >= 0 && nums[i - numberB]) {
			nums[i] = true;
		}
	}
	int answer = -1;
	for (auto n : nums) {
		if (n) {
			++answer;
		}
	}

	return answer;
}

// 아래는 테스트케이스를 출력해 보기 위한 main 함수입니다.
int main() {
	int numberA1 = 2;
	int numberB1 = 4;
	int limit1 = 10;
	int ret1 = solution(numberA1, numberB1, limit1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << "입니다." << endl;

	int numberA2 = 2;
	int numberB2 = 3;
	int limit2 = 10;
	int ret2 = solution(numberA2, numberB2, limit2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << "입니다." << endl;

	return 0;
}