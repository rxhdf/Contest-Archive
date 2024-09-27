#include <bits/stdc++.h>
#include <ios>
#define MAX (int)1e6 + 4
using namespace std;

int N, M, ans = 0;
vector<vector<int>> adj;

int dfs(int i, vector<bool> &vis){
     vis[i] = true;
    for(auto u: adj[i]){
        if(u == i + 1 && !vis[u]){
            dfs(u, vis);
        }else continue;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    adj.resize(N);
    for(int i = 1; i <= M; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < N; ++i){
        vector<bool> vis(N, 0);
        int res = 0;
        dfs(i, vis);
        for(int j = 0; j < N; ++j){
            res += vis[j] == 1? 1:0;
        }
        ans = max(ans, res);
    }
    cout << ans << "\n";
    return 0;
}