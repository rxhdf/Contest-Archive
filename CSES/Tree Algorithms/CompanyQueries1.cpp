#include <bits/stdc++.h>
#define MAXN (int)(2 * 1e5) + 10

using namespace std;

const int LOG = log2(MAXN);

vector<int> parents(MAXN);
vector<bool> visited(MAXN);
vector<int> adj[MAXN];
vector<vector<int>> up(LOG, vector<int> (MAXN));

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; ++i){
        cin >> parents[i];
        adj[i].push_back(parents[i]);
        adj[parents[i]].push_back(i);
    }
    //up[LOG][MAXN]
    parents[1] = -1;
    for(int i = 1; i <= n; ++i){
        up[1][i] = parents[i];
    }       

    for(int i = 2; i <= LOG; ++i){
        for(int j = 1; j <= n; ++j){
            if(up[i - 1][j] == -1){
                up[i][j] = -1;
            }else{
                up[i][j] = up[i - 1][up[i - 1][j]];
            }
            
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
    }
    
    return 0;
}