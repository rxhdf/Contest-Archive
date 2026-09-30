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
    vector<vector<char>> genetics(2 * n, vector<char>(m));
    for(int i = 0; i < 2 * n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> genetics[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < m; ++i){
        set<char> found;
        for(int j = 0; j < n; ++j){
            found.insert(genetics[j][i]);
        }
        bool ok = true;
        for(int j = n; j < 2 * n; ++j){
            if(found.find(genetics[j][i]) != found.end())ok = false;
        }
        if(ok)ans++;
    }
    cout << ans << "\n";
    return 0;
}