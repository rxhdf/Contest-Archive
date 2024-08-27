#include <bits/stdc++.h>

using namespace std;

int op = 0;

int dfs(int node, map<int, vector<int>> &tree, vector<int> &val){
    for(auto &child: tree[node]){
        if(val[node] >= val[child]){
            op = max(op, val[node] - val[child] + 1);
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int N;
        cin >> N;
        map<int, vector<int>> tree;
        vector<int> val(N + 1);
        for(int i = 1; i <= N; ++i){
            cin >> val[i];
        }
        tree[1] = 1;
        for(int i = 1; i < N; ++i){
            int parent;
            cin >> parent;
            tree[parent].push_back(i);
        }
        dfs(1, tree, val);
    }
    return 0;
}

