#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long int ans = (n * (n + 2) * (2 * n + 1)) / 8;
    cout << ans << "\n";
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