#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr, int N) {
	int frequency[101] = { 0 };

	for (int i = 0; i < N; i++) {
		frequency[arr[i]] += 1;
	}

	int best = 0;
	int num = 0;

	for (int i = 0; i <= 100; i++) {
		if (best <= frequency[i]) {
			best = frequency[i];
			if (num < i) {
				num = i;
			}
		}
	}

	return num;
}