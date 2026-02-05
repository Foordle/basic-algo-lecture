#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int tempMaxSum;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


bool inRange(int y, int x);
void dfs(int y, int x, int level, int sum);
int putTetromino(int y, int x);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    grid.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> grid[i][j];

    int result = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            result = max(result, putTetromino(i, j));

    cout << result;
    return 0;
}



bool inRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

void dfs(int y, int x, int level, int sum) {
    if (level == 3) {
        tempMaxSum = max(tempMaxSum, sum);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (inRange(ny, nx) && !visited[ny][nx]) {
            visited[ny][nx] = true;
            dfs(ny, nx, level + 1, sum + grid[ny][nx]);
            visited[ny][nx] = false;
        }
    }
}

int putTetromino(int y, int x) {
    int tetrominoResult = 0;
    for (int stare = 0; stare < 4; ++stare) {
        int tempSum = grid[y][x];
        for (int dir = 0; dir < 3; ++dir) {
            int curDir = (stare + dir) % 4;
            int ny = y + dy[curDir];
            int nx = x + dx[curDir];
            if (inRange(ny, nx)) {
                tempSum += grid[ny][nx];
            }
        }
        tetrominoResult = max(tetrominoResult, tempSum);
    }

    // DFS
    tempMaxSum = 0;
    visited[y][x] = true;
    dfs(y, x, 0, grid[y][x]);
    visited[y][x] = false;

    return max(tetrominoResult, tempMaxSum);
}
