#include <bits/stdc++.h>
using namespace std;

int n, m, x;
vector<vector<pair<int, int> > > graph;
vector<int> dist;

int dijkstra(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x;
    graph.resize(n + 1);

    for (int j = 1; j <= m; j++) {
        int v, u, w;
        cin >> v >> u >> w;
        graph[v].push_back({w, u});
    }

    int maxD = 0;
    for (int i = 1; i <= n; ++i) {
        int temp = dijkstra(i, x) + dijkstra(x, i);

        maxD = max(maxD, temp);
    }
    cout << maxD << '\n';
    return 0;
}

int dijkstra(int startV, int endV) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist.assign(n + 1, INT_MAX);
    dist[startV] = 0;
    pq.push({0, startV});
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curdist = pq.top().first;
        pq.pop();

        if (dist[cur] < curdist) {
            continue;
        }
        for (auto &nxt: graph[cur]) {
            int weight = nxt.first;
            int nxt_node = nxt.second;

            if (dist[nxt_node] > dist[cur] + weight) {
                dist[nxt_node] = dist[cur] + weight;
                pq.push({dist[nxt_node], nxt_node});
            }
        }
    }
    return dist[endV];
}

