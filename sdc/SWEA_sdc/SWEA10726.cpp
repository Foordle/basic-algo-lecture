#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    cin >> t;

    for (int testCaseN = 1; testCaseN <= t; testCaseN++) {
        cin >> n >> m;
        int mask = (1 << n) - 1;

        if ((m & mask) == mask) {
            cout << "#" << testCaseN << " ON\n";
        } else {
            cout << "#" << testCaseN << " OFF\n";
        }
    }

    return 0;
}