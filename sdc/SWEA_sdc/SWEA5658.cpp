#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;
    for (int t = 1; t <= testCase; ++t) {
        int n, k;
        cin >> n;
        string hexCode;
        cin >> hexCode;

        set<long long, greater<long long>> codes;
        int sideLen = n / 4;

        for (int rot = 0; rot < sideLen; ++rot) {
           for (int i = 0; i < n; i += sideLen) {
                string sub = hexCode.substr(i, sideLen);
                codes.insert(stoll(sub, nullptr, 16));
            }

            char last = hexCode.back();
            hexCode.pop_back();
            hexCode.insert(hexCode.begin(), last);
        }

        auto it = codes.begin();
        advance(it, k - 1); // 이전에 배운 advance를 써서 k-1만큼 이동!

        cout << "#" << t << " " << *it << "\n";
    }
    return 0;
}