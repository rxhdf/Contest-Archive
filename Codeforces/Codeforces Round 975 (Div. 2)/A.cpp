#include <bits/stdc++.h>
#include <ios>
#define ll long long int
using namespace std;

void solve(){
    ll n; 
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i <= n; i++) cin >> a[i];

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ll sz = n / 2 + (n % 2 == 1 && i % 2 == 1);
        ans = max(ans, a[i] + sz);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}