#include <bits/stdc++.h>
#define ll long long
using namespace std;


void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); 
    //freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

vector<pair<ll, ll>> factorize(ll x) {
    vector<pair<ll, ll>> res;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ll c = 0;
            while (x % i == 0){
                x /= i;
                c++;
            }
            res.push_back({i, c});
        }
    }
    if (x > 1) res.push_back({x, 1});
    return res;
}

int main() {
    setIO("");
    int tt, i = 1;
    cin >> tt;
    while(i <= tt){
        ll n, a, b;
        cin >> n >> a >> b;
        vector<pair<ll, ll>> factorization = factorize(b);
        vector<ll> vals;

        for (auto [p, e] : factorization){
            for (int i = 0; i < e; ++i){
                vals.push_back(p);       
            }
        }
        sort(vals.begin(), vals.end());

        vector<ll> fact(2 * n, 1);
        ll ans = 1;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (idx < (int)vals.size() && (ans * vals[idx]) < a){
                ans *= vals[idx];
                fact[i] = vals[idx];
                idx++;
            }
            else{
                fact[i] = 1;
            }
        }
        for (int i = n; i < 2 * n && idx < (int)vals.size(); i++){
            ans *= vals[idx];
            fact[i] = vals[idx];
            idx++;
        }
            
        sort(fact.begin(), fact.end());
        cout << "Case #" << i << ": ";
        for(auto e: fact){
            cout << e << " ";
        }
        cout << "\n";
        ++i;
    }
    
}
