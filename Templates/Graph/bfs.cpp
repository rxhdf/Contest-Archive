#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> distances1;
vector<vector<int>> adj;

void bfs(int start){
    queue<int> s;
    distances1[start] = 0;
    s.push(start);
    while(!s.empty()){
        int nxt = s.front();
        s.pop();
        for(auto e : adj[nxt]){
            if(distances1[e] == -1){
                distances1[e] = distances1[nxt] + 1;
                s.push(e);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    // number of nodes and edges
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    distances1.resize(n + 1, -1);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int initial_node = 1;
    distances1[initial_node] = 0;
    bfs(initial_node);
    for(auto e : distances1)cout << e << " ";
    cout << "\n";
    return 0;
}