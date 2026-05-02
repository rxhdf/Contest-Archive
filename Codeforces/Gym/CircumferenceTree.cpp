#include <bits/stdc++.h>
#define id first
#define distance second

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<vector<int>> tree(n);
    for(int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    //id, distance
    pair<int, int> farthest;
    auto dfs1 = [&](int node){
        stack<pair<int, int>> st;
        vector<bool> visited(n, false);
        farthest = {node, 0};
        st.push({node, 0});
        visited[node] = true;
        while(!st.empty()){
            auto actual = st.top();
            st.pop();
            if(actual.distance > farthest.distance){
                farthest = actual;
            }
            for(auto v: tree[actual.id]){
                if(!visited[v]){
                    visited[actual.id] = true;
                    st.push({v, actual.distance + 1});
                }
            }
        }
    };
    
    
    dfs1(0);
    dfs1(farthest.id);
    cout << farthest.distance * 3 << "\n";

    
    return 0;
}