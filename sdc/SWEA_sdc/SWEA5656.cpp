#include <bits/stdc++.h>
using namespace std;

int t, n, w, h;
int result;
// 우하, 좌하, 좌상, 우상
int dy[] = {1, 1, -1, 1};
int dx[] = {1, -1, -1, 1};

bool isOk(int y, int x) {
    return y >= 0 && y < h && x >= 0 && x < w;
}


int countRemaining(const vector<vector<int>>& graph) {
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] > 0) cnt++;
        }
    }
    return cnt;
}


void applyGravity(vector<vector<int>>& graph) {
    for (int j = 0; j < w; j++) {
        vector<int> temp;
        // 아래서부터 읽어서 벽돌만 저장
        for (int i = h - 1; i >= 0; i--) {
            if (graph[i][j] > 0) {
                temp.push_back(graph[i][j]);
                graph[i][j] = 0; // 일단 비움
            }
        }
        // 아래(h-1)부터 다시 채움
        for (int i = 0; i < temp.size(); i++) {
            graph[h - 1 - i][j] = temp[i];
        }
    }
}

void bfs(int row, int col, vector<vector<int>>& graph) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    q.push({row, col});
    visited[row][col] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        int power = graph[r][c];
        q.pop();

        graph[r][c] = 0;

        if (power <= 1) continue;

        for (int dir = 0; dir < 4; dir++) {
            // power - 1 만큼 뻗어나감
            for (int p = 1; p < power; p++) {
                int ny = r + dy[dir] * p;
                int nx = c + dx[dir] * p;

                if (isOk(ny, nx) && !visited[ny][nx] && graph[ny][nx] > 0) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
    applyGravity(graph);
}

void dfs(int cnt, vector<vector<int>> currentGraph) {

    result = min(result, countRemaining(currentGraph));

    if (cnt == n || result == 0) return; // 공을 다 던졌거나 벽돌이 없으면 종료

    for (int col = 0; col < w; col++) {
        int row = -1;
        // 해당 열의 가장 위에 있는 벽돌 찾기
        for (int i = 0; i < h; i++) {
            if (currentGraph[i][col] > 0) {
                row = i;
                break;
            }
        }

        if (row != -1) {
            vector<vector<int>> nextGraph = currentGraph;

            // 폭탄 터짐 처리
            bfs(row, col, nextGraph);

            // 다음 꺼
            dfs(cnt + 1, nextGraph);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (!(cin >> t)) return 0;

    for (int tc = 1; tc <= t; tc++) {
        cin >> n >> w >> h;
        vector<vector<int>> graph(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) cin >> graph[i][j];
        }

        result = countRemaining(graph); // 초기 벽돌 개수로 설정
        dfs(0, graph);

        cout << "#" << tc << " " << result << "\n";
    }
    return 0;
}