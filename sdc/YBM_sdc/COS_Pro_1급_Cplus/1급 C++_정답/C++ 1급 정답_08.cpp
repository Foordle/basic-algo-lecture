#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int numberA, int numberB, int limit) {
	int answer = 0;
	int check[1001] = { 0 };
	check[0] = 1;
	for (int i = min(numberA, numberB); i <= limit; i++) {
		if (i - numberA >= 0 && check[i - numberA] == 1)
			check[i] = 1;
		if (i - numberB >= 0 && check[i - numberB] == 1)
			check[i] = 1;
	}
	for (int i = 1; i <= limit; i++)
		answer += check[i];
	return answer;
}