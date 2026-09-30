#include <bits/stdc++.h>
#include <vector>

using namespace std;


vector<int> color;
vector<vector<int>> graph;

void match(int node){
    for(auto v: graph[node]){
        if(color[v] == -1){
            color[v] = 1 ^ color[node];
            match(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    color.assign(n + 1, -1);
    graph.assign(n + 1, {});
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }   
    color[1] = 0;
    match(1);
    
    long long ans = 0, total_blue = 0;

    for(int i = 1; i <= n; ++i){
        if(color[i] == 1){
            total_blue++;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(color[i] == 0){
            ans += total_blue - graph[i].size();
        }
    }
    cout << ans << "\n";
    return 0;
}