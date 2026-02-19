#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int start, vector<int> locations) {
	int answer = 0;
	int min = 100; //here
	int max = 0;
	for (int i = 0; i < locations.size(); i++) {
		if (locations[i] < min) min = locations[i];
		if (locations[i] > max) max = locations[i];
	}

	if (start <= min)
		answer = max - start;
	else if (start >= max)
		answer = start - min;
	else {
		if (start - min < max - start)
			answer = start - min + (max - min);
		else
			answer = max - start + (max - min);
	}

	return answer;
}