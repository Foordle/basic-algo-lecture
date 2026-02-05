#include <bits/stdc++.h>
using namespace std;

int n, t;
int startX, startY;
int result;
// 우하, 좌하, 좌상, 우상
int dy[] = {1, 1, -1, -1};
int dx[] = {1, -1, -1, 1};
bool dessert[101] ={false};
vector<vector<int>> graph;


void solve(int, int , int, int);
bool isInRange(int, int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        // stdin
        cin >> n;
        graph.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
        }

        result = -1;

        // solve
        for (startY = 0; startY < n; startY++) {
            for (startX = 0; startX < n; startX++) {

                // set param
                memset(dessert, false, sizeof(dessert));
                dessert[graph[startY][startX]] = true;
                // solve
                solve(startY, startX,0, 1);
                // reset
                dessert[graph[startY][startX]] = false;
            }
        }



        cout << "#" << tc << " " << result << "\n";
    }
    return 0;
}

void solve(int y, int x, int dir, int nOfDesserts) {
    // if ( x ==  4 && y == 0) {
    //     int mmmmm = 0;
    // }
    // 직진 | 방향 꺽기
    for (int i = 0; i < 2; i++) {

        int nxtDir = dir+i;
        if (nxtDir == 4) {
            break;
        }

        int ny = y + dy[nxtDir];
        int nx = x + dx[nxtDir];

        if (ny == startY && nx == startX && nxtDir >= 3) {
            result = max(result, nOfDesserts);
            return;
        }
        if (isInRange(ny, nx) && !dessert[graph[ny][nx]]) {
            dessert[graph[ny][nx]] = true;
            solve(ny, nx, nxtDir, nOfDesserts+1);
            dessert[graph[ny][nx]] = false;
        }

    }
}


bool isInRange(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}