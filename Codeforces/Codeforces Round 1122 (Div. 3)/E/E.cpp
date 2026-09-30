#include <bits/stdc++.h>
#include <climits>

using namespace std;

int n, k;
const int nax = (int)4e5 + 1;
vector<long long> primes[nax];
vector<bool> is_primes(nax, false);

void calc() {
    for (long long i = 2; i <= 200000; i++) {
        if (!is_primes[i]) {
            is_primes[i]=true;
            for (long long j = 2*i; j <= 200000; j+=i) {
                primes[j].push_back(i);
                is_primes[j]=true;
            }
            primes[i].push_back(i);
        }
    }
}

void solve(){
    cin >> n >> k;
    vector<long long> dp(n + 1, LONG_LONG_MAX);
    for(long long i = 1; i <= n; ++i){
        if(i <= k){
            dp[i] = 0;
        }else{
            for(auto p: primes[i]){
                //cout << p << " ";
                dp[i] = min(dp[i], (dp[i / p] * p + 1));
            }
        }
    }   
    long long ans = 0; 
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        ans += dp[x];
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    calc();
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;   
}

