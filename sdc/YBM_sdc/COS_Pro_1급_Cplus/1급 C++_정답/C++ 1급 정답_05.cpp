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
			answer = i; //here
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