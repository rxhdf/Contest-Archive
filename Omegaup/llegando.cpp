#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }
    priority_queue<

    int p
    cin >> p;
    while(p--){
        int x, y;
        cin >> x >> y;

    }
    return 0;
}