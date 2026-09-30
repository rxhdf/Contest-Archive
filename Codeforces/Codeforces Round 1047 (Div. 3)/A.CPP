#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int k, x;
        cin >> k >> x;
        long long ans = x;
        for(int i = 1; i <= k; ++i){
            ans *= 2;
        }
        cout << ans << "\n";
    }
    return 0;
}
