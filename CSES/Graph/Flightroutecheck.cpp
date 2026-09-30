#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); 
    //freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

vector<bool> visited;
vector<vector<int>> adj;

void dfs(int node){
    visited[node] = true;
    for(auto u: adj[node]){
        if(visited[u])continue;
        dfs(u);
    }
}

int main() {
    setIO("");
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int j = 1; j <= n; ++j){
        fill(visited.begin(), visited.end(), false);
        dfs(j);
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                cout << "NO\n";
                cout << j << " " << i << "\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}