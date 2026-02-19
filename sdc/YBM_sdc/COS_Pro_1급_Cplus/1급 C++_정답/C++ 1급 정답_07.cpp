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
		if (arr[i]) //here
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
