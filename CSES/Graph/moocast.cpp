#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int maxComponent = 0;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, int &aux){
    visited[node] = true;
    aux++;
    for(auto u: graph[node]){
        if(visited[u])continue;
        dfs(u, graph, visited, aux);
    }
}

int main() {
    setIO("moocast");
    int n;
    cin >> n;
    vector<array<long long, 3>> cow(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> cow[i][0] >> cow[i][1] >> cow[i][2];
    }    
    vector<vector<int>> graph(n + 1);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)continue;
            long long distance = (abs(cow[i][0] - cow[j][0]) * abs(cow[i][0] - cow[j][0])) + (abs(cow[i][1] - cow[j][1]) * abs(cow[i][1] - cow[j][1]));
            if(distance <= cow[i][2] * cow[i][2]){
                graph[i].push_back(j);
            }
        }
    }
    
    for(int i = 1; i <= n; ++i){
        int x = 0;
        vector<bool> visited(n + 1, false);
        dfs(i, graph, visited, x);
        maxComponent = max(x, maxComponent);
    }
    cout << maxComponent << "\n";
    return 0;
}