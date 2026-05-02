#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        vector<int> a(7);
        for(int i = 0; i < 7; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 0; i < 7; ++i){
            ans += (i < 6)? -a[i]: a[i];
        }
        cout << ans << "\n";
    }

    return 0;
}