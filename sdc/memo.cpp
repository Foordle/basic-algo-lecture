#include <bits/stdc++.h>
using namespace std;


int n, m;
int bitMask = 0;
vector<pair<string, int>> guitars;

void playGuitar(int level, int bitMask) {
    if (level == n) {
        return;
    }
    if (bitMask == (1<<n)-1) {

    }
    int temp  = bitMask;
    // 선택함
    bitMask |=  (1<<level);
    playGuitar(level+1, bitMask);


    bitMask = temp;
    // 선택 안함
    playGuitar(level+1, bitMask);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    guitars.resize(n);
    for (int i = 0; i < n; ++i) {
        string gName;
        cin >> gName;

        int code = 0;
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j) {
            if (str[j] == 'Y') {
                code |= (1<<i);
            }
        }

        guitars[i] = {gName, code};
    }



    return 0;
}