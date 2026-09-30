#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int mn = INT32_MAX;
    for(int i = 0; i < 3; ++i){
        int x;
        cin >> x;
        mn = min(x, mn);
    }
    cout << n - mn << "\n";
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

