#include <bits/stdc++.h>
using namespace std;

int n, m, sv, ev;
vector<vector<pair<int, int> > > graph;
vector<int> dist;

void dijkstra();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dist.assign(n + 1, INT_MAX);
    graph.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        graph[v].push_back({w, u});
    }

    cin >> sv >> ev;
    dijkstra();
    cout << dist[ev];

    return 0;
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, sv});
    dist.push_back(sv);
    while (!pq.empty()) {
        int curV = pq.top().second;
        int curD = pq.top().first;
        pq.pop();
        if (dist[curV] < curD) {
            continue;
        }
        for (auto nxt: graph[curV]) {
            int nxtV = nxt.second;
            int nextD = nxt.first;
            if (dist[nxtV] > curD + nextD) {
                dist[nxtV] = curD + nextD;
                pq.push({dist[nxtV], nxtV});
            }
        }
    }
}
