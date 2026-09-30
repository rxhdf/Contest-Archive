// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> ans(2 * n, 0);
    ans[n] = n;
    for(int i = 0; i < n; ++i){
        ans[i] = n - i;
    }
    int j = 1;
    for(int i = n + 1; i < 2 * n; ++i){
        ans[i] = j;
        ++j;
    }
    for(auto e: ans){
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
