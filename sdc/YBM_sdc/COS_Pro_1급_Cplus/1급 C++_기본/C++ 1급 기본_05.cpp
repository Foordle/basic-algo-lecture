#include <string>
#include <vector>
#include <iostream>

using namespace std;

int func_a(vector<int> arr) {
	int answer = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (answer == -1)
			answer = i;
		else if (arr[answer] < arr[i])
			answer = i;
	}
	return answer;
}

vector<int> func_b(vector<string> arr1, vector<string> arr2) {
	vector<int> answer(arr1.size());
	for (int i = 0; i < arr1.size(); i++) {
		for (int j = 0; j < arr2.size(); j++)
			if (arr1[i] == arr2[j])
				answer[i]++;
	}
	return answer;
}

int func_c(vector<int> arr, int number) {
	int answer = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == number)
			continue;
		if (answer == -1)
			answer = i;
		else if (arr[answer] < arr[i])
			answer += 1;
	}
	return answer;
}

vector<string> solution(vector<string> menu, vector<string> votes) {
	vector<int> counter = func_b(menu, votes);
	int first = func_a(counter);
	int second = func_c(counter, counter[first]);

	vector<string> answer;
	answer.push_back(menu[first]);
	answer.push_back(menu[second]);
	return answer;
}

// 아래는 테스트케이스를 출력해 보기 위한 main 함수입니다.
int main() {
	vector<string> menuA = {"Latte", "Americano","Espresso" };
	vector<string> votesA = { "Latte", "Americano", "Espresso", "Latte", "Americano", "Americano", "Latte", "Americano", "Americano", "Latte", "Latte", "Latte" };
	vector<string> retA = solution(menuA, votesA);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 {" << retA[0] << ", " << retA[1] << "} 입니다." << endl;

	vector<string> menuB = { "MochaLatte", "GreenTea", "Cappuccino" };
	vector<string> votesB = { "GreenTea", "GreenTea", "MochaLatte", "GreenTea", "Cappuccino", "Cappuccino" };
	vector<string> retB = solution(menuB, votesB);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 {" << retB[0] << ", " << retB[1] << "} 입니다." << endl;
	return 0;
}
