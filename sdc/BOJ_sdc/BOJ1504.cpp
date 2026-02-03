#include <bits/stdc++.h>
using namespace std;

int dijkstra(int, int);

vector<vector<pair<int, int> > > graph;
vector<int> dist;

int n, e;
bool flag = false;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> e;
    graph.resize(n + 1);
    for (int i = 1; i <= e; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        graph[v].push_back({w, u});
        graph[u].push_back({w, v});
    }
    int v1, v2;
    cin >> v1 >> v2;
    int minL = min(dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n)
                   , dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n));
    if (flag) minL = -1;
    cout << minL << '\n';
    return 0;
}


int dijkstra(int sV, int eV) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;


    const int INF = INT_MAX;
    dist.assign(n + 1, INF);

    dist[sV] = 0;
    pq.push({0, sV});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curV = pq.top().second;
        pq.pop();

        if (dist[curV] < curDist) continue;

        for (auto nxt: graph[curV]) {
            int weight = nxt.first; // 현재 간선의 가중치
            int nxtV = nxt.second; // 연결된 다음 정점

            // 2. 가중치를 더해서 비교
            if (dist[nxtV] > curDist + weight) {
                dist[nxtV] = curDist + weight;
                pq.push({dist[nxtV], nxtV});
            }
        }
    }
    if (dist[eV] == INF) flag = true;
    return dist[eV];
}
