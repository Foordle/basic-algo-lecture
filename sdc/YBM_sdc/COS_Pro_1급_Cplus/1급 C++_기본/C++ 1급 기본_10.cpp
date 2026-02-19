#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(vector<int> &a, vector<int> &b) {
	if (a[1] != b[1]) return a[1] > b[1];
	else if (a[2] != b[2]) return a[2] > b[2];
	else if (a[3] != b[3]) return a[3] > b[3];
	else if (a[4] != b[4]) a[4] > b[4];
	return a[0] < b[0];
}

vector<int> solution(vector<vector<int>> household) {
	sort(household.begin(), household.end(), compare);
	vector<int> answer;
	for (int i = 0; i < household.size(); i++) {
		answer.push_back(household[i][0]);
	}

	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.
int main() {
	vector<vector<int>> household = { {1, 1, 2, 60}, {2, 1, 2, 85},	{3, 0, 0, 70}, {4, 0, 0, 70}, {5, 1, 3 , 90} };
	vector<int> ret = solution(household);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 {" << ret[0] << ", " \
		<< ret[1] << ", " << ret[2] << ", " << ret[3] \
		<< ", " << ret[4] << "}입니다." << endl;
	return 0;
}
