#include <bits/stdc++.h>

#define MAXN (int)2e5

using namespace std;

int N;
vector<vector<int>> adj(MAXN);
int subts[MAXN], depth[MAXN];

void dfs(int x){
    subts[x] = 1;
    for(auto e: adj[x]){
        depth[e] = depth[x] + 1;
        dfs(e);
        subts[x] += subts[e];
    }
}

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
    }
    dfs(0);
    for(int i = 0; i < N; ++i){
        cout << subts[i] << " ";
    }
    return 0;
}