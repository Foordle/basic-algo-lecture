#include <iostream>
#include <vector>
using namespace std;

string solution(int money, vector<vector<int>> cost, vector<string> name) {
	string answer ="";
	long max_distance = 0;

	for (int i = 0; i < cost.size(); i++) {
		int oil = money / cost[i][1];
		long distance = cost[i][0] * oil;
		if (distance > max_distance) {
			max_distance = distance;
			answer = name[i];
		}
	}

	return answer;
}