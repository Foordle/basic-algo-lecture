
#include <bits/stdc++.h>
using namespace std;

int grid[8][8];
bool visited[8][8];
int maxLength = 0;
vector<pair<int, int>> peaks;

int n;
int k;

int dy[] = {-1, 0, 1, 0}; // 상0 우1 하2 좌3
int dx[] = {0, 1, 0, -1};

bool inRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int r, int c, bool useK, int curLength, int curH) {

    visited[r][c] = true;

    if (curLength > maxLength) {
        maxLength = curLength;
    }

    for (int dir = 0; dir < 4; ++dir) {
        int nr = r + dy[dir];
        int nc = c + dx[dir];

        if (inRange(nr, nc) && !visited[nr][nc]) {

            // 그냥 갈 수 있음
            if (curH > grid[nr][nc] ) {
                dfs(nr, nc, useK, curLength + 1, grid[nr][nc]);
            }

            // k로 깍아서 갈 수 있음
            else if (!useK && (curH > grid[nr][nc] - k) ) {
                dfs(nr, nc, true, curLength + 1, curH-1);
            }

        }
    }

    visited[r][c] = false;

}

int main() {
    int testCase;
    cin >> testCase;
    for (int t = 1; t <= testCase; ++t) {

        memset(visited, false, sizeof(visited));
        memset(grid, 0, sizeof(grid));
        peaks.clear();
        maxLength = 0;

        cin >> n >> k;

        int peak = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
                if (peak < grid[i][j]) {
                    peak = grid[i][j];
                    peaks.clear();
                    peaks.push_back({i, j});
                }
                else if (peak == grid[i][j]) {
                    peaks.push_back({i, j});
                }
            }
        }




        for (auto p: peaks) {
            dfs(p.first, p.second, false, 1, grid[p.first][p.second]);
        }


        cout << '#' << t << ' ' << maxLength<< '\n';

    }
    return 0;
}