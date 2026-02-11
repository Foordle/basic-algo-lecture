#include <bits/stdc++.h>

using namespace std;

int N, total_eaten;
// 전역 선언 --> 그냥 미리 배열로 해두는게 좋대!
int grid[51][51];
bool eaten[51][51];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool inRange(int y, int x) {
    return (y >= 0 && y < N && x >= 0 && x < N);
}

void solve(int level, int y, int x) {
    if (level == 3) return;

    for (int dir = 0; dir < 4; ++dir) {
        bool isVault  = false;
        int ny = y;
        int nx = x;

        while (true) {
            ny += dy[dir];
            nx += dx[dir];
            if (!inRange(ny, nx)) {
                break;
            }

            // 첫 쫄 만나기 전
            if (!isVault) {
                if (grid[ny][nx] == 1) {
                    isVault = true;
                }
            }

            // 첫 쫄 이미 만났습니다.
            else {

                // 오늘밤 사냥에 나선다!
                if (grid[ny][nx] == 1) {

                    if (!eaten[ny][nx]) {
                        eaten[ny][nx] = true;
                        total_eaten++;
                    }

                    int temp = grid[ny][nx];
                    grid[ny][nx] = 0;

                    // 다음 depth로!
                    solve(level + 1, ny, nx);

                    // 복구
                    grid[ny][nx] = temp;


                    break;
                }

                // 쫄이 아니였어... 못먹습니다..
                else {
                    solve(level + 1, ny, nx);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        int sy, sx;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 2) {
                    sy = i; sx = j;
                    grid[i][j] = 0;
                }
                eaten[i][j] = false;
            }
        }

        total_eaten = 0;
        solve(0, sy, sx);

        cout << "#" << t << " " << total_eaten << "\n";
    }
    return 0;
}