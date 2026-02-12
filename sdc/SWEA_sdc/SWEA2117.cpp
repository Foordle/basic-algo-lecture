#include<bits/stdc++.h>

using namespace std;

int n, m;
int maxN = 20;
int maxM = 10;
int grid[20][20];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int calculateOperatingExpress(int k) {
    return k * k + (k - 1) * (k -1);
}

bool inRange(int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < n && grid[r][c] != -1;
}

int checkArea(int r, int c, int k) {
    int cnt = 0;
    int dist = k - 1;
    for (int nr = r - dist; nr <= r + dist; ++nr) {

        for (int nc = c - dist; nc <= c + dist; ++nc) {

            if (abs(nr-r) + abs(nc-c) >= k) continue;
            if (!inRange(nr, nc)) continue;

            if (grid[nr][nc] == 1) {
                ++cnt;
            }

        }
    }

    return cnt;
}

// int checkArea(int r, int c, int k) {
//     int cnt = 0;
//     int dist = k - 1;
//     for (int nr = r - dist; nr <= r + dist; ++nr) {
//
//         for (int nc = c - dist; nc <= c + dist; ++nc) {
//
//             if (abs(nr - r) + abs(nc - c) < k) {
//                 if (inRange(nr, nc)) { // 범위 체크
//
//                     if (grid[nr][nc] == 1) cnt++;
//                 }
//             }
//         }
//     }
//     return cnt;
// }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int testCase;
    cin >> testCase;
    for (int t = 1; t <= testCase; ++t) {
        cin >> n >> m;
        fill(grid[0], grid[maxN], -1);



        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        int result = 0;


        for (int k = 1; k <= n + 1; ++k) { // K 범위 확장
            int cost = calculateOperatingExpress(k);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int tempHouseN = checkArea(i, j, k);
                    if (tempHouseN * m - cost >= 0) {
                        result = max(result, tempHouseN);
                    }
                }
            }
        }

        cout <<"#"<<t<<" "<<result<<'\n';
    }
    return 0;
}