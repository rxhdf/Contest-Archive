#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, r, ans = 0;
    cin >> l >> r;
    for(int i = l; i <= r; ++i){
        if(i & 1)ans++;
    }
    cout << ans / 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }

    return 0;
}