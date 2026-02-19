#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define ALPHANUM (26)

void func1(int number, vector<vector<bool>> &arr1, vector<bool> &arr2) {
	arr2[number] = true;
	for (int i = 0; i < ALPHANUM; i++)
		if (arr1[number][i] && !arr2[i])
			func1(i, arr1, arr2);
}

int func2(vector<bool> &arr) {
	int answer = 0;
	for (int i = 0; i < ALPHANUM; i++)
		if (!arr[i])
			answer++;
	return answer;
}

void func3(vector<string> &arr1, vector<vector<bool>> &arr2) {
	for (int i = 0; i < arr1.size(); i++) {
		int num1 = arr1[i][0] - 'A';
		int num2 = arr1[i][1] - 'A';
		arr2[num1][num2] = true;
		arr2[num2][num1] = true;
	}
}

int solution(vector<string> list) {
	vector<vector<bool>> graph(ALPHANUM, vector<bool>(ALPHANUM));
	vector<bool> visited(ALPHANUM);

	func3(list, graph);
	visited[0] = true;
	for (int node = 0; node < ALPHANUM; node++)
		if (graph[0][node] && !visited[node])
			func1(node, graph, visited);
	return func2(visited);
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	vector<string> list = { "AB", "BC", "DE", "CF" };
	int ret = solution(list);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
	return 0;
}