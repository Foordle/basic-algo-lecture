#include <cstring>
#include <iostream>
#include <string>
#define MAXH 21
#define MAXW 21
using namespace std;

int row, col, n, dir, curX, curY;
int grid[MAXH][MAXW];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char dChar[] = {'^', '>', 'v', '<'}; // 방향 인덱스를 기호로 매핑

bool inRange(int y, int x) {
    return (x >= 0 && x < col && y >= 0 && y < row);
}

void move() {
    int newX = curX + dx[dir];
    int newY = curY + dy[dir];
    if (inRange(newY, newX) && grid[newY][newX] == -1) {
        curX = newX;
        curY = newY;
    }
}

void shoot() {
    int sX = curX + dx[dir];
    int sY = curY + dy[dir];
    while (inRange(sY, sX)) {
        if (grid[sY][sX] == -2) { // 벽돌
            grid[sY][sX] = -1;
            break;
        }
        else if (grid[sY][sX] == -3) { // 강철
            break;
        }
        sX += dx[dir];
        sY += dy[dir];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int testCaseN; cin >> testCaseN;

    for (int testCase = 1; testCase <= testCaseN; ++testCase) {
        cin >> row >> col;
        for (int i = 0; i < row; ++i) {
            string s; cin >> s;
            for (int j = 0; j < col; ++j) {
                if (s[j] == '.') grid[i][j] = -1;
                else if (s[j] == '*') grid[i][j] = -2;
                else if (s[j] == '#') grid[i][j] = -3;
                else if (s[j] == '-') grid[i][j] = -4;
                else { // 탱크 위치
                    grid[i][j] = -1; curX = j; curY = i;
                    if (s[j] == '^') dir = 0;
                    else if (s[j] == '>') dir = 1;
                    else if (s[j] == 'v') dir = 2;
                    else if (s[j] == '<') dir = 3;
                }
            }
        }

        cin >> n;
        string order; cin >> order;
        for (char c : order) {
            if (c == 'U') { dir = 0; move(); }
            else if (c == 'D') { dir = 2; move(); }
            else if (c == 'L') { dir = 3; move(); }
            else if (c == 'R') { dir = 1; move(); }
            else if (c == 'S') { shoot(); }
        }

        cout << "#" << testCase << " ";
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == curY && j == curX) cout << dChar[dir];
                else if (grid[i][j] == -1) cout << '.';
                else if (grid[i][j] == -2) cout << '*';
                else if (grid[i][j] == -3) cout << '#';
                else if (grid[i][j] == -4) cout << '-';
            }
            cout << "\n";
        }
    }
    return 0;
}