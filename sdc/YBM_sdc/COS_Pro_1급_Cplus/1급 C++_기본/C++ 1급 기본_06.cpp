#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int start, vector<int> locations) {
	int answer = 0;
	int min = 0;
	int max = 0;
	for (int i = 0; i < locations.size(); i++) {
		if (locations[i] < min) min = locations[i];
		if (locations[i] > max) max = locations[i];
	}

	if (start <= min)
		answer = max - start;
	else if (start >= max)
		answer = start - min;
	else {
		if (start - min < max - start)
			answer = start - min + (max - min);
		else
			answer = max - start + (max - min);
	}

	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니, 위의 코드만 수정하세요.
int main() {
	int start = 15;
	vector<int> locations = { 10, 62, 22 };
	int ret = solution(start, locations);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}