#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int NAX = 3000000;
vector<int> dp(NAX, 0);

int collatz(ll n){
    if(n == 1) return 1;
    if(n < NAX && dp[n]) return dp[n];
    int res;
    if(n & 1) res = 1 + collatz(3*n + 1);
    else res = 1 + collatz(n/2);
    if(n < NAX) dp[n] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a; i <= b; i++){
        ans = max(ans, collatz(i));
    }
    cout << ans << "\n";
    return 0;
}
