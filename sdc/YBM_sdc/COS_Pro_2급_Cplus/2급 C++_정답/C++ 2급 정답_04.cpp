#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr, int N, int M) {
	int min_sum = 50000;
	int max_sum = 0;

	for (int i = 0; i < N - M + 1; i++) {
		int temp_max = 0;
		for (int j = i; j < i + M; j++) {
			temp_max += arr[j];
		}
		if (temp_max > max_sum) {
			max_sum = temp_max;
		}
		if (temp_max < min_sum) {
			min_sum = temp_max;
		}
	}

	return max_sum - min_sum;
}