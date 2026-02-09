#include <bits/stdc++.h>
using namespace std;

int n, k, m, T;
vector<int> p;

// find 함수 수정: x < 0이 아니라 p[x] < 0을 확인해야 합니다.
int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int v, int u) {
    int vR = find(v), uR = find(u);
    if (vR == uR) return false;
    if (p[vR] > p[uR]) swap(vR, uR);
    if (p[vR] == p[uR]) --p[vR];
    p[uR] = vR;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> T)) return 0; // 테스트 케이스 개수 T를 먼저 받습니다.

    for (int tc = 1; tc <= T; tc++) {
        cin >> n; // 유저 수
        p.assign(n, -1); // 유저가 0부터 n-1까지이므로 n개 할당

        cin >> k; // 친구 관계 수
        while (k--) {
            int a, b;
            cin >> a >> b;
            uni(a, b);
        }

        cin >> m; // 질문 수
        cout << "Scenario " << tc << ":\n";
        while (m--) {
            int u, v;
            cin >> u >> v;
            if (find(u) == find(v)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        cout << "\n"; // 각 테스트 케이스 사이에는 빈 줄 출력
    }

    return 0;
}