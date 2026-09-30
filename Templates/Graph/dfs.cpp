#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> distances1, distances2;
vector<vector<int>> adj;

void dfs_recursive(int start){
    for(auto nxt : adj[start]){
        if(distances1[nxt] == -1){
            distances1[nxt] = distances1[start] + 1;
            dfs_recursive(nxt);
        }
    }   
}
void dfs_iterative(int start){
    stack<int> s;
    distances2[start] = 0;
    s.push(start);
    while(!s.empty()){
        int nxt = s.top();
        s.pop();
        for(auto e : adj[nxt]){
            if(distances2[e] == -1){
                distances2[e] = distances2[nxt] + 1;
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
    distances2.resize(n + 1, -1);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int initial_node = 1;
    distances1[initial_node] = distances2[initial_node] = 0;
    dfs_recursive(initial_node);
    dfs_iterative(initial_node);
    for(auto e : distances1)cout << e << " ";
    cout << "\n";
    for(auto e : distances2)cout << e << " ";
    cout << "\n";
    return 0;
}