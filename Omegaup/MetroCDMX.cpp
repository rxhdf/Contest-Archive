#include <bits/stdc++.h>
#define ll long long int
#define MAXN (int)1e6 + 5

using namespace std;

ll P, D, Q;
vector<vector<ll>> adj;
bool dp[MAXN];
bool aux[MAXN];

ll dfs(int node){
    if(!adj[node].size())return aux[node] = 1;
    if(dp[node])return aux[node];
    ll sum = 0;
    dp[node] = true;
    for(auto &v: adj[node]){
        sum += dfs(v);
    }
    if(sum == adj[node].size())return aux[node] = 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> P >> D >> Q;
    adj.resize(P + 2);
    for(int i = 0; i < D; ++i){
        int x, y;
        cin >> x >> y;
        for(int j = 0; j < y; ++j){
            int z;
            cin >> z;
            adj[x].push_back(z);
        }
    }
    for(int i = 1; i <= P; ++i){
        if(!aux[i]){
            dfs(i);
        }
    }
    while(Q--){
        int x;
        cin >> x;
        bool yeah = true;
        for(int i = 0; i < x; ++i){
            int y;
            cin >> y;
            if(!aux[y]){
                yeah = false;
            }
        }
        cout << (yeah ? "S\n" : "N\n");
    }
    return 0;
}