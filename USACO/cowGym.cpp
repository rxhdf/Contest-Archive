#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("gymnastics");
    int k, n;
    cin >> k >> n;
    vector<vector<int>> m(k, vector<int>(n + 1));
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n; ++j){
            int a;
            cin >> a;
            m[i][a] = j;            
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)continue;
            int cnt = 0;
            for(int l = 0; l < k; ++l){
                if(m[l][i] < m[l][j])cnt++;
            }
            if(cnt == k)ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}