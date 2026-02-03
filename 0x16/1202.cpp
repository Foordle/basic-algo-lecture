#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> hi;

int main() {
    cin >> n;
    hi.assign(n, 0);
 int maxI = 0, maxHi = 0, cur = 0, pre = 0;
    for (int i = 1; i < n+1; ++i) {
        cin >> pre;
        hi[i] = pre;
        if (maxHi > abs(cur - pre)) {
            maxHi = cur - pre;
            maxI = i;
        }
        cur = nxt;
    }

    return 0;
}