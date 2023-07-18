#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K, D;
ll MOD = 1e9 + 7;

int DP[105][2];

ll solve(ll sum, bool valid){
    if(sum > N)return 0;
    if(sum == N && valid)return 1;
    if(DP[sum][valid] != -1) return DP[sum][valid];
    ll resultForThisState = 0;
    for(ll i=1; i<=K; i++){
        resultForThisState += solve(sum + i, i >= D || valid) % MOD;
    }
    return DP[sum][valid] = resultForThisState % MOD;
}

int main() {
  memset(DP, -1, sizeof(DP));
    cin >> N >> K >> D;
    cout << solve(0, false) % MOD;
    return 0;
}