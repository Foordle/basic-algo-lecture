
#include<bits/stdc++.h>

using namespace std;

void morningMove();

bool canMove();

void afternoonMove();

int dayTime = 0, growCnt = 0;
int INF = 1e9;
int tempMaxHarvest, maxHarvest, testCase, n, m, dir;
int robotRow, robotCol;
// 지도 정보
// -1: 산, 0: 농지, 1~k : k일에 수확 가능
vector<vector<int> > grid;
// 좌, 상, 우, 하 순으로 움직임, 이전과 달리 dir을 계속 ++하되 막히면 이전꺼로 돌아감..
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> testCase;
    for (int t = 1; t <= testCase; ++t) {
        // stdin
        cin >> n >> m;
        grid.assign(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int inputN;
                cin >> inputN;
                if (inputN == 1) inputN = -1;
                grid[i][j] = inputN;
            }
        }

        tempMaxHarvest = 0, maxHarvest = 0;
        dayTime = 0, growCnt = 0;

        // solve
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    // 1. 상태 복사 및 초기화
                    vector<vector<int> > backupGrid = grid;
                    int currentM = m; // m값 보존
                    dayTime = 0;
                    tempMaxHarvest = 0;
                    robotRow = i;
                    robotCol = j;
                    dir = k;

                    // 2. m일 동안 시뮬레이션
                    for (int d = 1; d <= currentM; ++d) {
                        dayTime = d;
                        morningMove();
                        afternoonMove();
                    }

                    // 3. 결과 갱신 및 그리드 복구
                    maxHarvest = max(maxHarvest, tempMaxHarvest);
                    grid = backupGrid;
                }
            }
        }
        cout << '#' << t << ' ' << maxHarvest << '\n';
    }
    return 0;
}

// -1: 산, 0: 농지, 1~k : k일에 수확 가능
void morningMove() {
    int cur = grid[robotRow][robotCol];
    if (cur == 0) {
        // - 현재 농지가 빈 농지이고 로봇이 다음 농지로 이동할 수 있는 경우 씨를 심는다.
        if (canMove()) {
            growCnt++;
            grid[robotRow][robotCol] = growCnt + 3 + dayTime;
        }
        // - 현재 농지가 빈 농지이고, 로봇이 다음 농지로 이동할 수 없을 경우 아무것도 하지 않고 현재 위치에서 머무른다.
        else {
        }
    }
    // - 현재 농지에 곡식이 열린 경우 수확을 한다. 수확을 하면 농지는 빈 농지가 된다.
    if (cur > 0 && cur <= dayTime) {
        grid[robotRow][robotCol] = 0;
        tempMaxHarvest++;
    }
}

void afternoonMove() {
    if (!canMove()) return;
    for (int i = 0; i < 4; ++i) {
        dir = (dir + i) % 4;
        int nrow = robotRow + dy[dir];
        int ncol = robotCol + dx[dir];
        if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n) continue;
        int nxt = grid[nrow][ncol];
        if (nxt != -1 && !(nxt > dayTime + 1)) {
            robotRow = nrow;
            robotCol = ncol;
            break;
        }
    }
}

bool canMove() {
    bool result = false;
    for (int i = 0; i < 4; ++i) {
        int nrow = robotRow + dy[i];
        int ncol = robotCol + dx[i];
        if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n) continue;
        int nxt = grid[nrow][ncol];
        // 산이 아니고 dayTime보다 작으면 이동 가능..
        if (nxt != -1 && !(nxt > dayTime + 1)) {
            result = true;
            break;
        }
    }
    return result;
}
