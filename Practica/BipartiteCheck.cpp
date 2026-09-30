#include <bits/stdc++.h>

using namespace std;

void is_bipartite(vector<vector<int>> &graph){
    vector<int> side(graph.size(), -1);
    bool is_b = true;
    queue<int> q;
    for(int i = 1; i <= graph.size(); ++i){
        if(side[i] == -1){
            q.push(i);
            side[i] = 0;
            while(!q.empty()){
                int nxt = q.front();
                q.pop();
                for(auto u: graph[nxt]){
                    if(side[u] == -1){
                        side[u] = side[nxt] ^ 1;
                        q.push(u);
                    }else{
                        is_b &= side[u] != side[nxt];
                    }
                }
            }
        }
    }
    if(is_b){
        for(int i = 1; i < side.size(); ++i){
            cout << (side[i] == 1 ? 2 : 1) << " ";
        }
    }else{
        cout << "IMPOSSIBLE\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt = 1;
   // cin >> tt;
    for(int i = 1; i <= tt; ++i){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        is_bipartite(graph);
    }

    return 0;
}