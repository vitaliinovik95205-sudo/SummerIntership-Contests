#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, ll>>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    

    vector<ll> dist(n + 1, LLONG_MAX);
    
    vector<int> parent(n + 1, -1);
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if (d != dist[v]) continue;
        
        for (auto [to, w] : graph[v]) {
            if (dist[v] + w < dist[to]) {
                dist[to] = dist[v] + w;
                parent[to] = v;
                pq.push({dist[to], to});
            }
        }
    }
    
    if (dist[n] == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }
    
    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
    
    return 0;
}
