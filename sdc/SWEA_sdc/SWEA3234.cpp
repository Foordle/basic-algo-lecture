#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d, w, k, result;
int grid[14][21];

bool checkPerformance() {
    if (k == 1) return true;
    for (int j = 0; j < w; ++j) {
        int cur_cnt = 1;
        for (int i = 0; i < d - 1; ++i) {
            if (grid[i][j] == grid[i + 1][j]) cur_cnt++;
            else cur_cnt = 1;

            if (cur_cnt >= k) break;
        }
        if (cur_cnt < k) return false;
    }
    return true;
}

void dfs(int row, int usage) {
    if (usage >= result) return; // 가지치기
    if (row == d) {
        if (checkPerformance()) result = usage;
        return;
    }

    // 약품 투입 안 함
    dfs(row + 1, usage);

    // 백업
    int backup[21];
    for (int i = 0; i < w; i++) backup[i] = grid[row][i];

    // 약품 투입
    for (int drugType = 0; drugType < 2; ++drugType) {
        // 행 전체를 drugType으로 한 번에 변경
        for (int i = 0; i < w; i++) {
            grid[row][i] = drugType;
        }


        dfs(row + 1, usage + 1);
    }

    // 복구
    for (int i = 0; i < w; i++) {
        grid[row][i] = backup[i];
    }
}
 int main(){
        int testCase;
        cin >> testCase;
        for (int t = 1; t <= testCase; ++t) {
            cin >> d >> w >> k;
            for (int i = 0; i < d; ++i)
                for (int j = 0; j < w; ++j) cin >> grid[i][j];

            result = k;


            if (checkPerformance()) result = 0;
            else dfs(0, 0);

            cout << '#' << t << ' ' << result << '\n';
        }
        return 0;
}
