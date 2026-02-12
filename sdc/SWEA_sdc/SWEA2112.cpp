#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int obj[10];
int fact[10];
int pow2[10];

int solve(int mask, int l, int r) {
    // 이미 모든 추를 다 쓴 경우
    if (mask == (1 << n) - 1)
        return 1;

    int remain_sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) {
            remain_sum += obj[i];
            cnt++;
        }
    }
    if (l >= r + remain_sum) {
        return fact[cnt] * pow2[cnt];
    }


    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) {
            // 왼쪽
            res += solve(mask | (1 << i), l + obj[i], r);

            // 오른쪽
            if (l >= r + obj[i]) {
                res += solve(mask | (1 << i), l, r + obj[i]);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    fact[0] = 1; pow2[0] = 1;
    for(int i=1; i<10; i++) {
        fact[i] = fact[i-1] * i;
        pow2[i] = pow2[i-1] * 2;
    }

    int testCase;
    cin >> testCase;
    for (int t = 1; t <= testCase; ++t) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> obj[i];

        cout << '#' << t << ' ' << solve(0, 0, 0) << '\n';
    }
    return 0;
}