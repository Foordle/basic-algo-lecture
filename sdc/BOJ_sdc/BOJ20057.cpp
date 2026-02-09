#include <bits/stdc++.h>
using namespace std;

int n, m, x;
vector<vector<pair<int, int> > > graph;
vector<int> dist;


int main() {

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

