#include <bits/stdc++.h>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    
    for(int i = 0; i < m; ++i){
        char c;
        cin >> c;
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, (c == 'S')});
        graph[v].push_back({u,(c == 'S')});
    }

    vector<int> color(n + 1, -1);

    int components = 0;
    bool can = true;

    for(int i = 1; i <= n; ++i){
        if(color[i] == -1){
            components++;
            queue<pair<int, int>> q;
            q.push({i, 1});

            while(!q.empty()){
                auto actual = q.front();
                q.pop();
                color[actual.first] = actual.second;

                for(auto v: graph[actual.first]){
                    int type = (v.second? v.second: !v.second);
                    if(color[v.first] == -1){
                        q.push({v.first, type});
                    }
                    else if(color[v.first] == !type){
                        can = false;
                        break;
                    }
                }
            }
        }
    }

    if(can){
        cout << 1;
        for(int i = 0; i < components; ++i){
            cout << 0;
        }
        cout << "\n";
    }else{
        cout << "0\n";
    }

    return 0;
}