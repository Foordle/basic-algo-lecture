#include <bits/stdc++.h>
#define endl "\n"
#define maxID 100000
#define maxTeam 5
#define maxScore 5
using namespace std;

struct soldier {
    int mID;
    int mTeam;
    int mScore;
};

soldier soldierArr[6][maxSoldierID];

void init() {

}
// 병사 고용
void hire(int mID, int mTeam, int mScore) {
    soldierArr[mTeam][mID] =
        soldier{
            mID,
            mTeam,
            mScore
        };
}

void fire(int mID) {

}

void updateSoldier(int mID, int mScore) {

}
void updateTeam(int mTeam, int mChangeScore) {

}
int bestSoldier(int Team) {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}