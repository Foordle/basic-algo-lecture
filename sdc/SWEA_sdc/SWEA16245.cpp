#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int INF = 1e9;
int cityCount;
unordered_map<int, int> cityMap;

struct Edge {
    int to, cost;
};
vector<Edge> adj[605];        // 정방향
vector<Edge> revAdj[605];     // 역방향

// 도시 번호를 0~599 인덱스로 변환
int getCityIdx(int id) {
    if (cityMap.find(id) == cityMap.end()) {
        cityMap[id] = cityCount++;
    }
    return cityMap[id];
}

int dijkstra(int start, vector<Edge> graph[]) {
    vector<int> dist(605, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < d) continue;

        for (auto& edge : graph[curr]) {
            if (dist[edge.to] > d + edge.cost) {
                dist[edge.to] = d + edge.cost;
                pq.push({-dist[edge.to], edge.to});
            }
        }
    }

    int total = 0;
    for (int i = 0; i < cityCount; i++) {
        if (dist[i] != INF) total += dist[i];
    }
    return total;
}

int init(int N, int sCity[], int eCity[], int mCost[]) {
    cityMap.clear();
    cityCount = 0;
    for (int i = 0; i < 605; i++) { adj[i].clear(); revAdj[i].clear(); }

    for (int i = 0; i < N; i++) {
        int u = getCityIdx(sCity[i]);
        int v = getCityIdx(eCity[i]);
        adj[u].push_back({v, mCost[i]});
        revAdj[v].push_back({u, mCost[i]});
    }
    return cityCount;
}

void add(int sCity, int eCity, int mCost) {
    int u = getCityIdx(sCity);
    int v = getCityIdx(eCity);
    adj[u].push_back({v, mCost});
    revAdj[v].push_back({u, mCost});
}

int cost(int mHub) {
    int hubIdx = getCityIdx(mHub);
    // (허브 -> 각 도시) + (각 도시 -> 허브)
    return dijkstra(hubIdx, adj) + dijkstra(hubIdx, revAdj);
}