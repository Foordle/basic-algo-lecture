#include <iostream>
#include <vector>

using namespace std;

struct Atom {
    int x, y, dir, k;
    bool isAlive;
};

// 좌표계 2배 확대 (-2000 ~ 2000) -> 0 ~ 4000
int MAP[4001][4001];
int dx[] = { 0, 0, -1, 1 }; // 상(0), 하(1), 좌(2), 우(3)
int dy[] = { 1, -1, 0, 0 };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N; cin >> N;
        vector<Atom> atoms(N);
        for (int i = 0; i < N; i++) {
            int x, y, d, k;
            cin >> x >> y >> d >> k;
            // 좌표 2배 확대 및 오프셋 적용
            atoms[i] = { (x + 1000) * 2, (y + 1000) * 2, d, k, true };
        }

        int totalEnergy = 0;
        for (int step = 0; step <= 4000; step++) {
            vector<pair<int, int>> visited; // 이번 턴에 원자가 도달한 위치 저장


            for (int i = 0; i < N; i++) {
                if (!atoms[i].isAlive) continue;

                int nx = atoms[i].x + dx[atoms[i].dir];
                int ny = atoms[i].y + dy[atoms[i].dir];

                if (nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
                    atoms[i].isAlive = false;
                    continue;
                }

                atoms[i].x = nx;
                atoms[i].y = ny;

                if (MAP[ny][nx] == 0) visited.push_back({ny, nx});
                MAP[ny][nx] += atoms[i].k; // 해당 좌표에 에너지 누적
            }

            // 2. 충돌 처리
            for (int i = 0; i < N; i++) {
                if (!atoms[i].isAlive) continue;

                int cx = atoms[i].x;
                int cy = atoms[i].y;

                if (MAP[cy][cx] > atoms[i].k) {
                    // 누적 에너지가 본인 에너지보다 크면 충돌 발생
                    totalEnergy += MAP[cy][cx];
                    MAP[cy][cx] = 0;
                    atoms[i].isAlive = false;
                }
            }


            for (auto p : visited) {

                MAP[p.first][p.second] = 0;

            }


            for(int i=0; i<N; i++) {
                if(atoms[i].isAlive && MAP[atoms[i].y][atoms[i].x] == 0) {
                    atoms[i].isAlive = false;
                }
            }
        }
        cout << "#" << tc << " " << totalEnergy << "\n";
    }
    return 0;
}