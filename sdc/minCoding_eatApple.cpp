#include <bits/stdc++.h>

using namespace std;

int N, resultCnt = 0;
// 전역 선언 --> 그냥 미리 배열로 해두는게 좋대!
int grid[51][51];
bool eaten[51][51];
queue<pair<int, int>> target;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int dir = 0;

bool inRange(int y, int x) {
    return (y >= 0 && y < N && x >= 0 && x < N);
}

bool canReach(int y, int x, queue<pair<int, int>>& q, bool useQue) {
    while (true) {
        ny += dy[dir];
        nx += dx[dir];
        if (!inRange(ny, nx)) {
            break;
        }
        // 직진으로 갈 수 있다면
        if (thisTarget.first == ny && thisTarget.second == nx) {
            return true;
        }
        if (usQue)
            q.push({nx, ny});

    }
    return false;
}

void moveToTarget(int y, int x) {
    int ny = y;
    int nx = x;
    pair<int, int> thisTarget = target.front();
    target.pop();
    while (canReach(ny, nx, q, ))




}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {


        cin >> N;
        int sequence = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
                if (Sequence == grid[i][j]) {
                    sequence++;
                    target.push({i, j});
                }

            }
        }



        cout << "#" << t << " "  << "\n";


    }
    return 0;
}