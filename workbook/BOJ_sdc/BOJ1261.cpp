#include <bits/stdc++.h>
using namespace std;
int n, m;
const int INF = 1e9;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct cell {
    int d;
    int y;
    int x;

    bool operator>(const cell &c) const {
        return d > c.d;
    }
};


vector<vector<int> > grid;
vector<vector<int> > dist;

void dijkstra();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    grid.assign(n + 1, vector<int>(m + 1, -1));
    dist.assign(n + 1, vector<int>(m + 1, INF));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            grid[i][j] = s[j - 1] - '0';
        }
    }

    dijkstra();

    cout << dist[n][m] << endl;

    return 0;
}

void dijkstra() {
    priority_queue<cell, vector<cell>, greater<cell> > pq;
    pq.push({0, 1, 1});
    dist[1][1] = 0;
    while (!pq.empty()) {
        cell cur = pq.top();
        pq.pop();
        if (dist[cur.y][cur.x] < cur.d) {
            continue;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (ny > 0 && ny <= n && nx > 0 && nx <= m) {
                if (dist[ny][nx] > dist[cur.y][cur.x] + grid[ny][nx]) {
                    dist[ny][nx] = dist[cur.y][cur.x] + grid[ny][nx];
                    pq.push(cell({dist[ny][nx], ny, nx}));
                }
            }
        }
    }
}

