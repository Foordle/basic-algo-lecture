#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
	if (a[1] != b[1]) return a[1] > b[1]; 
	if (a[2] != b[2]) return a[2] > b[2]; 
	return a[0] < b[0];		
}

vector<int> solution(vector<vector<int>> projects) {
	sort(projects.begin(), projects.end(), compare);

	vector<int> answer;
	for (int i = 0; i < projects.size(); i++)
		answer.push_back(projects[i][0]);
	return answer;
}
