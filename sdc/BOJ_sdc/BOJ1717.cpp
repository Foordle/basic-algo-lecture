#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p;
int find(int x);
bool uni(int v, int u);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    p.assign(n+1, -1);
    for (int i = 1; i <= m; ++i) {
        int type, a, b;
        bool isSame = false;
        cin >> type >> a >>b;
        switch (type) {
            case 0: {
                uni(a, b);
                break;
            }
            case 1: {
                isSame = find(a) == find(b);
                string result = isSame ? "YES" : "NO";
                cout << result << '\n';
                break;
            }
            default:
                break;
        }


    }


    return 0;
}

int find(int x) {
    if (p[x] < 0) return x;

    return p[x] = find(p[x]);
}

bool uni(int v, int u) {
    int vR = find(v);
    int uR = find(u);
    if (vR == uR) return false;
    if (p[vR] > p[uR]) {
        swap(vR, uR);
    }

    if (p[vR] == p[uR]) {
        --p[vR];
    }

    p[uR] = vR;
    return true;

}