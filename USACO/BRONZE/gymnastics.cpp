#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    int k, p;
    cin >> k >> p;
    vector<vector<int>> m(k, vector<int>(n, 0));
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n; ++j){
            cin >> m[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int counter = 0;
        for(int j = 0; j < n; ++j){
            bool ok = true;
            for(int h = 0; h < k; ++h){
                if()
            }
            if(ok)counter++;
        }
        ans += counter;
    }
    cout << ans << "\n";
    return 0;
}