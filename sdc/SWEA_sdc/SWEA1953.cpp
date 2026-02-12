
#include <bits/stdc++.h>
using namespace std;

int grid[50][50];
bool visited[50][50];
int n, m, sr, sc, l;

int dy[] = {-1, 0, 1, 0}; // 상0 우1 하2 좌3
int dx[] = {0, 1, 0, -1};

vector<vector<int>> pipes = {
    {},
    {0, 1, 2, 3},
    {0, 2},
    {3, 1},
    {0, 1},
    {2, 1},
    {2, 3},
    {0, 3}
};

bool canConnect(int nextPipe, int dir) {
    int oppDir = (dir + 2) % 4;
    for (int d : pipes[nextPipe]) {
        if (d == oppDir) return true;
    }
    return false;
}
bool inRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int bfs() {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    int time = 1;
    int ans = 1;

    while (!q.empty()) {
        if (time == l) break;
        int size = q.size();

        while(size--) {
            pair<int, int> cur = q.front();
            q.pop();

            for (auto dir : pipes[grid[cur.first][cur.second]]) {
                int nr = cur.first + dy[dir];
                int nc = cur.second + dx[dir];

                if (inRange(nr, nc)) {
                    if (!visited[nr][nc] && grid[nr][nc] != 0) {
                        if (canConnect(grid[nr][nc], dir)) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                            ++ans;
                        }
                    }
                }
            }
        }
        ++time;
    }
    return ans;
}

int main() {
    int testCase;
    cin >> testCase;
    for (int t = 1; t <= testCase; ++t) {

        cin >> n >> m >> sr >> sc >> l;
        memset(visited, false, sizeof(visited));
        memset(grid, -1, sizeof(grid));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cin >> grid[i][j];
        }

        cout << '#' << t << ' ' << bfs() << '\n';

    }
    return 0;
}