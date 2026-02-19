#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> arr, int N, int J) {
	int now = 0;

	queue<int> q;

	for (int i = 0; i < N; i++) {
		q.push(arr[i]);
	}

	while (J > 0) {
		int eat = q.front();
		q.pop();
		J -= eat;
		q.push(eat);
		now += 1;

		if (now > N) {
			now = 1;
		}
	}

	return now;

}