#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    int targetMask = (1 << 10) - 1; // 0~9비트가 모두 1인 상태

    for (int testCaseN = 1; testCaseN <= t; testCaseN++) {
        cin >> n;

        int bitMask = 0;
        int num = 0;
        int currentN = 0;


        while (bitMask != targetMask) {
            num++;
            currentN = num * n;

            int temp = currentN;

            if (temp == 0) bitMask |= (1 << 0);
            while (temp > 0) {
                bitMask |= (1 << (temp % 10));
                temp /= 10;
            }
        }

        cout << "#" << testCaseN << " " << currentN << "\n";
    }

    return 0;
}