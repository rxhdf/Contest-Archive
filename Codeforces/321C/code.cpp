#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    vector<vector<int>> tree(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int ans = 0;
    auto BFS = [](vector<vector<int>>& tree, int cats, int& ans, vector<int>& pos){
        queue<pair<int, int>> q;
        vector<bool> visited(tree.size() + 1, false);
        visited[1] = true;
        q.push(make_pair(1, pos[1]));
        while(!q.empty()){
            auto actual = q.front();
            q.pop();
            if(tree[actual.first].size() == 1 && actual.first != 1){
                ans++;
                continue;
            }
            for(auto v: tree[actual.first]){
                if(!visited[v]){
                    pair<int, int> nxtCat = make_pair(v, pos[v] == 1? actual.second + 1: 0);
                    if(nxtCat.second <= cats){
                        visited[v] = true;
                        q.push(nxtCat);
                    }                  
                }
            }
        }
    };
    BFS(tree, m, ans, a);
    cout << ans << "\n";
    return 0;
}