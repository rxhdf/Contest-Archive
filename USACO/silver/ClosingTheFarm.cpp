#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int component_size = 0;
vector<int> closed;
vector<bool> visited;
vector<vector<int>> adj;
set<int> closedYet;

void dfs(int node){
    component_size++;
    visited[node] = true;
    for(auto u: adj[node]){
        if(closedYet.find(u) != closedYet.end() || visited[u])continue;
        dfs(u);
    }
}

int main() {
    setIO("closing");
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    closed.resize(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; ++i){
        cin >> closed[i];
    }
    dfs(1);
    if(component_size == n){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    for(int i = 0; i < n - 1; ++i){
        component_size = 0;
        closedYet.insert(closed[i]);
        fill(visited.begin(), visited.end(), false);
        dfs(closed[n - 1]);
        if(component_size ==  n - i - 1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}