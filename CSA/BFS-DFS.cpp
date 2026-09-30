#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dfs(n);
    vector<int> bfs(n);

    for(auto &e: bfs){
        cin >> e;
    }
    for(auto &e: dfs){
        cin >> e;
    }

    if(n == 1){
        cout << "0\n";
    }
    else if(dfs[1] != bfs[1]){
        cout << "-1\n";
    }
    else{
        cout << 2 * n - 3 << "\n";
        for(int i = 1; i < n; ++i){
            cout << 1 << " " << bfs[i] << "\n";
        }
        for(int i = 1; i < n - 1; ++i){
            cout << dfs[i] << " " << dfs[i + 1] << "\n";
        }
    }

    return 0;
}