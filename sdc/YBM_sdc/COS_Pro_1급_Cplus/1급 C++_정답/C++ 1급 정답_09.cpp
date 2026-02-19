#include <iostream>
#include <vector>


using namespace std;

int find(int x, vector<int> adj) {
	if (adj[x] == x) return x;
	return find(adj[x], adj);
}

vector<int> unionFunc(int a, int b, vector<int> adj) {
	a = find(a, adj);
	b = find(b, adj);
	if (a != b) adj[b] = a;

	return adj;
}

int solution(int participant, vector<vector<int>> info, vector<vector<int>> game) {

	int result = 0;

	vector<int> adj(participant);

	for (int i = 0; i < participant; i++) {
		adj[i] = i;
	}

	for (int i = 0; i < game.size(); i++) {
		int first = game[i][0];
		for (int j = 1; j < game[i].size(); j++) {
			adj = unionFunc(first, game[i][j], adj);
		}
	}

	for (int i = 0; i < game.size(); i++) {
		bool isChecked = true;
		int cur = game[i][0];
		for (int j = 0; j < info[1].size(); j++) {
			if (find(cur, adj) == find(info[1][j], adj)) {
				isChecked = false;
				break;
			}
		}
		if (isChecked) result++;
	}

	int answer = result;
	return answer;
}

