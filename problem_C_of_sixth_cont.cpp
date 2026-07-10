#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> parent;
vector<bool> visited;
int target;
bool found_way = false;

void dfs(int v) {
    if (found_way){
        return;
    } 
    
    visited[v] = true;
    
    if (v == target) {
        found_way = true;
        return;
    }
    
    for (int to : graph[v]) {
        if (!visited[to]) {
            parent[to] = v;
            dfs(to);
            if (found_way){
                return;
            } 
        }
    }
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, u, v;
    cin >> n >> m >> u >> v;
    
    graph.assign(n + 1, {});
    parent.assign(n + 1, -1);
    visited.assign(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    target = v;
    
    dfs(u);
    
    if (!found_way) {
        cout << -1 << endl;
    } 
    else {
        vector<int> path;
        for (int cur = v; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    
    
    return 0;
}
