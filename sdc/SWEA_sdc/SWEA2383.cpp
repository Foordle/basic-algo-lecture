#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct Person {
    int r, c;
};

struct Stair {
    int r, c, k;
};

int N, M;
vector<Person> persons;
vector<Stair> stairs;

// 특정 계단에 배정된 사람들이 모두 내려가는 시간을 계산하는 시뮬레이션
int solve(const vector<int>& arrivalTimes, int stairK) {
    if (arrivalTimes.empty()) return 0;

    // 도착 시간 순으로 정렬
    vector<int> times = arrivalTimes;
    sort(times.begin(), times.end());

    // 계단에서 나가는 시간을 관리하는 PQ (오름차순)
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int arrive : times) {
        // 계단 입구 도착 후 1분 뒤부터 진입 가능
        int readyTime = arrive + 1;

        if (pq.size() < 3) {
            // 계단에 자리가 있으면 바로 진입
            pq.push(readyTime + stairK);
        } else {
            // 자리가 없으면 가장 빨리 나가는 사람을 기다림
            int earliestExit = pq.top();
            pq.pop();

            // 대기 후 진입 (나가는 시간과 준비 시간 중 늦은 시간 기준)
            int startTime = max(readyTime, earliestExit);
            pq.push(startTime + stairK);
        }
    }

    // 마지막 사람이 나가는 시간이 곧 완료 시간
    int lastTime = 0;
    while (!pq.empty()) {
        lastTime = pq.top();
        pq.pop();
    }
    return lastTime;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        persons.clear();
        stairs.clear();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int val; cin >> val;
                if (val == 1) persons.push_back({i, j});
                else if (val > 1) stairs.push_back({i, j, val});
            }
        }

        M = persons.size();
        int minTotalTime = 1e9;

        // Bit Masking: 2^M 가지의 계단 선택 조합
        for (int i = 0; i < (1 << M); ++i) {
            vector<int> group0, group1;
            for (int j = 0; j < M; ++j) {
                int dist = abs(persons[j].r - stairs[i & (1 << j) ? 1 : 0].r) +
                           abs(persons[j].c - stairs[i & (1 << j) ? 1 : 0].c);

                if (i & (1 << j)) group1.push_back(dist);
                else gro
                up0.push_back(dist);
            }

            // 각 계단별 완료 시간 중 더 늦은 시간이 전체 완료 시간
            int res0 = solve(group0, stairs[0].k);
            int res1 = solve(group1, stairs[1].k);
            minTotalTime = min(minTotalTime, max(res0, res1));
        }

        cout << "#" << t << " " << minTotalTime << endl;
    }
    return 0;
}