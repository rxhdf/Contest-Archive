#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> parents;
vector<vector<int>> graph;
vector<bool> visited;

int dfs(int node, int parent){
    if(visited[node]){
        return parent;
    }
    visited[node] = true;
    for(auto nxt: graph[node]){
        visited[nxt] = true;
        parents[nxt] = node;
        if(!visited[nxt])dfs(nxt, node);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    parents.resize(n + 1, -1);
    visited.resize(n + 1, false);
    graph.resize(n + 1);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //iota(parents.begin(), parents.end(), 0);
    cout << dfs(1, 1) << "\n";

    return 0;
}