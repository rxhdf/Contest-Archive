#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("cownomics");
    int n, m;
    cin >> n >> m;
    vector<vector<char>> gen(m, vector<char>(2 * n));
    for(int i = 0; i < 2 * n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> gen[j][i];
        }
    }
    int ans = 0;
    for(int i = 0; i < m; ++i){
        set<char> m1, m2;
        for(int j = 0; j < 2 * n; ++j){
            if(j < n){
                m1.insert(gen[i][j]);
            }else{  
                m2.insert(gen[i][j]);
            }
        }
        bool ok = true;
        for(auto e: m1){
            if(m2.find(e) != m2.end()){
                ok = false;
                break;
            }
        }
        if(ok)ans++;
    }
    cout << ans << "\n";
    return 0;
}