#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    ll n;
    cin >> n;
    set<ll> r;
    vector<ll> l(n), c(n);

    for(ll i = 0; i < n; ++i){
        cin >> l[i];
    }
    for(ll i = 0; i < n; ++i){
        ll x;
        cin >> x;
        r.insert(x);
    }
    for(ll i = 0; i < n; ++i){
        cin >> c[i];
    }
    sort(l.begin(), l.end());
    sort(c.rbegin(), c.rend());
    ll ans = 0;
    vector<ll> len;
    for(ll i = n - 1; i >= 0; --i){
        auto itr = r.upper_bound(l[i]);
        if (itr != r.end()) {
            len.push_back(*itr - l[i]);
            r.erase(itr);
            
        }
    }
    sort(len.begin(), len.end());
    for(ll i = 0; i < n; ++i){
        ans += len[i] * c[i];
    }
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