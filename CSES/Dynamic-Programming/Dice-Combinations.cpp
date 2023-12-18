#include <bits/stdc++.h> 
#define MOD 1000000007
#define MAX 1000001
#define ll long long 

using namespace std;
 
ll dp[MAX];
 
ll sum(ll n){
    if(dp[n] != 0)return dp[n];
    for(ll i = 1; i <= 6; ++i){
        if(n - i >= 0){
            dp[n] += sum(n - i);
            dp[n] %= MOD;
        }
    }
    return dp[n];
} 
    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
    memset(dp, 0 , sizeof(dp));
    dp[0] = 1;
    cout << sum(n) << "\n";
    return 0;
}

