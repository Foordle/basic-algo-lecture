#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;
vector<vector<int>> grid;
vector<int> p;
queue<pair<int, int>> q;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) return false;


    if (p[rootA] > p[rootB]) swap(rootA, rootB);
    p[rootA] += p[rootB];
    p[rootB] = rootA;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    grid.assign(n + 1, vector<int>(n + 1, -1));
    p.assign(k, -1);

    vector<pair<int, int>> initial_pos;
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        if (grid[r][c] != -1) {
            if (uni(i, grid[r][c])) k--;
        }
        grid[r][c] = i;
        initial_pos.push_back({r, c});
        q.push({r, c});
    }


    for (auto cur : initial_pos) {
        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
            if (grid[ny][nx] != -1) {
                if (uni(grid[cur.first][cur.second], grid[ny][nx])) k--;
            }
        }
    }

    if (k <= 1) { cout << 0; return 0; }


    while (!q.empty()) {
        int size = q.size();
        cnt++;
        for (int s = 0; s < size; s++) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if (ny < 1 || ny > n || nx < 1 || nx > n) continue;

                if (grid[ny][nx] == -1) {
                    grid[ny][nx] = grid[cur.first][cur.second];
                    q.push({ny, nx});


                    for (int j = 0; j < 4; j++) {
                        int nny = ny + dy[j];
                        int nnx = nx + dx[j];
                        if (nny < 1 || nny > n || nnx < 1 || nnx > n) continue;
                        if (grid[nny][nnx] != -1) {
                            if (uni(grid[ny][nx], grid[nny][nnx])) {
                                if (--k == 1) { cout << cnt; return 0; }
                            }
                        }
                    }
                } else {

                    if (uni(grid[cur.first][cur.second], grid[ny][nx])) {
                        if (--k == 1) { cout << cnt; return 0; }
                    }
                }
            }
        }
    }

    return 0;
}