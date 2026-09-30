#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); 
}

ll modpow(ll a, ll b, ll mod){
    ll res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod){
    return modpow(a, mod - 2, mod);
}

ll nCr_large(ll n, ll r){
    if(r < 0 || r > n) return 0;
    if(r > n - r) r = n - r;
    
    ll res = 1;
    for(ll i = 1; i <= r; i++){
        res = res * (n - r + i) % MOD;
        res = res * modinv(i, MOD) % MOD;
    }
    return res;
}

ll count_distributions(ll e, ll N){
    if(e == 0) return 1; 
    return nCr_large(e + N - 1, N - 1);
}

void solve(int idx, ll current_product, const vector<ll>& primes, const vector<ll>& max_exponents, ll n, ll a, ll& total_ways, vector<ll>& current_exponents) {
    if(idx == primes.size()){
        if(current_product > a) return;
        
        ll f1 = 1;
        for(int i = 0; i < primes.size(); i++){
            f1 = f1 * count_distributions(current_exponents[i], n) % MOD;
        }
        
        ll f2 = 1;
        for(int i = 0; i < primes.size(); i++){
            ll rem = max_exponents[i] - current_exponents[i];
            f2 = f2 * count_distributions(rem, n) % MOD;
        }
        
        total_ways = (total_ways + f1 * f2 % MOD) % MOD;
        return;
    }
    
    ll p = primes[idx];
    ll max_exp = max_exponents[idx];
    ll max_possible = 0;
    ll temp = current_product;
    while(max_possible < max_exp && temp <= a / p){
        temp *= p;
        max_possible++;
    }
    
    for(ll exp = 0; exp <= max_exp; exp++){
        if(exp > max_possible) break;
        
        ll new_product = current_product;
        for(int j = 0; j < exp; j++){
            new_product *= p;
        }
        if(new_product > a) break;
        
        current_exponents[idx] = exp;
        solve(idx + 1, new_product, primes, max_exponents, n, a, total_ways, current_exponents);
    }
}

int main() {
    setIO("");
    int tt, i = 1;
    cin >> tt;
    
    while(i <= tt){
        ll n, a, b;
        cin >> n >> a >> b;
        
        vector<pair<ll, ll>> factors;
        ll temp = b;
        for(ll p = 2; p * p <= temp; ++p){
            if(temp % p == 0){
                ll cnt = 0;
                while(temp % p == 0){
                    temp /= p;
                    cnt++;
                }
                factors.push_back({p, cnt});
            }
        }
        if(temp > 1){
            factors.push_back({temp, 1});
        }
        
        vector<ll> primes;
        vector<ll> max_exponents;
        for(auto [p, e] : factors){
            primes.push_back(p);
            max_exponents.push_back(e);
        }
        
        ll total_ways = 0;
        vector<ll> current_exponents(primes.size(), 0);
        solve(0, 1, primes, max_exponents, n, a, total_ways, current_exponents);
        
        cout << "Case #" << i << ": " << total_ways << "\n";
        ++i;
    }
    
    return 0;
}