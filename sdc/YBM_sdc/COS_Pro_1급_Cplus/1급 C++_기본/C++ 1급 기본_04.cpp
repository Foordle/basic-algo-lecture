#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int maxNumber(int value) {
	vector<int> numbers;
	for (int i = 0; i < 4; i++, [[quiz]])
		numbers.push_back([[quiz]]);
	sort([[quiz]]);
	int maxNum = 0;
	for (int i = 0; i < 4; i++)
		maxNum = [[quiz]];
	return maxNum;
}

int minNumber(int value) {
	vector<int> numbers;
	for (int i = 0; i < 4; i++,[[quiz]])
		numbers.push_back([[quiz]]);
	sort([[quiz]]);
	int minNum = 0;
	for (int i = 0; i < 4; i++)
		minNum = [[quiz]];
	return minNum;
}

int solution(int num) {
	int answer;
	int maxiNum = maxNumber(num);
	int minNum = minNumber(num);
	answer = [[quiz]];
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int num1 = 5924;
	int ret1 = solution(num1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int num2 = 3904;
	int ret2 = solution(num2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
	return 0;
}