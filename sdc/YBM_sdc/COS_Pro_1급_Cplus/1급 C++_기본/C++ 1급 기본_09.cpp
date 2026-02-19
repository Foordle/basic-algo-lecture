#include <iostream>
#include <vector>

using namespace std;

vector<int> p;
vector<bool> type;
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool uni(int v, int u) {
	int pV = find(v);
	int pU = find(u);

	if (pV == pU) return false;

	if (p[pV] < p[pU]) {
		swap(pV, pU);
	}
	--p[pV];
	p[pU] = pV;

	return true;
}


int solution(int N, vector<vector<int>> info, vector<vector<int>> game) {
	int result = 0;
	p.assign(N, -1);
	type.assign(N, false);
	for (int i = 0; i < info[0][0]; ++i) {
		type[info[1][i]] = true;
		uni(0, info[1][i]);
	}
	for (auto g: game) {
		for (int i = 0; i+1 < g.size(); ++i) {
			uni(i, i+1);


		}

	}
	for (auto g: game) {
		bool isWin = true;
		for (auto person :  g) {
			if (!uni(0, person)) {
				isWin = false;
			}
		}
		if (isWin) {
			result++;
		}
	}



	return result;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int N = 5;
	vector<vector<int>> info = { { 1 }, { 4 } };// 전략 알고 있는 놈들{명 수}, {실제 놈들}
	vector<vector<int>> game = { { 1,2 }, {3}, { 3, 4 } }; // 각 게임마다 진행하는 친구들

	int ret = solution(N, info, game);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
    
    
    int N2 = 7;
	vector<vector<int>> info2 = { { 3 }, { 1, 2, 3 }};
	vector<vector<int>> game2 = { {1}, {2}, {3}, {4}, {5}, {6}, {4, 5}, {3, 6} };

	int ret2 = solution(N2, info2, game2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
    
    
	return 0;
}
