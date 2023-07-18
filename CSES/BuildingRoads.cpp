#include <iostream>
#include <vector>

using namespace std;

int n, m, r = 0;
vector<vector<int>> adj(100001);
vector<bool> visited(100001);
vector<int> roads;
void dfs(int i){
    visited[i] = true;
    for(auto e: adj[i]){
        if(!visited[e]){
            dfs(e);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            dfs(i);
            r++;
            roads.push_back(i);
        }
    }
    cout << r - 1 << "\n";
    for(int i = 1; i < r; ++i){
        cout << roads[i-1] << " " << roads[i] << "\n";
    }
}