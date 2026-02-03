
#include<bits/stdc++.h>

using namespace std;

void moveOneStep(int, int);

int INF = 1e9;
int tempMaxHarvest, testCase, n, m, dir;
// 지도 정보
// -1: 산, 0: 농지, 1~k : k일에 수확 가능
vector<vector<int> > grid;
// 좌, 상, 우, 하 순으로 움직임, 이전과 달리 dir을 계속 ++하되 막히면 이전꺼로 돌아감..
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> testCase;
    for (int t = 1; t <= testCase; ++t) {
        tempMaxHarvest = 0;

        // stdin
        cin >> n >> m;
        grid.assign(n, vector<int>(n, 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int inputN;
                if (inputN == 1) inputN = -1;
                grid[i][j] = inputN;
            }
        }
        // solve
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dir = 0; // 최초 방향 설정
                // 시작점 세팅
                int x = j;
                int y = i;
                // m일동안 움직임
                while (m--) {
                    moveOneStep(y, x);
                }
            }
        }
    }
    return 0;
}

void moveOneStep(int row, int col) {
    // 씨 심고 이동
    // 막혀서 우회
    // 정상


    // 수확

    // 이동 못하니 그냥 놔둠 -> else로 아무것도 안하고 끝
}

