#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int maxNumber(int value) {
	vector<int> numbers;
	for (int i = 0; i < 4; i++, value /= 10)
		numbers.push_back(value % 10);
	sort(numbers.begin(), numbers.end(), greater<int>());
	int maxNum = 0;
	for (int i = 0; i < 4; i++)
		maxNum = maxNum * 10 + numbers[i];
	return maxNum;
}

int minNumber(int value) {
	vector<int> numbers;
	for (int i = 0; i < 4; i++, value /= 10)
		numbers.push_back(value % 10);
	sort(numbers.begin(), numbers.end());
	int minNum = 0;
	for (int i = 0; i < 4; i++)
		minNum = minNum * 10 + numbers[i];
	return minNum;
}

int solution(int num) {
	int answer;
	int maxiNum = maxNumber(num);
	int minNum = minNumber(num);

	answer = abs(maxiNum - minNum);
	return answer;
}