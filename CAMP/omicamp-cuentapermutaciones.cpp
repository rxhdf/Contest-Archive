#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> pre(200001, 0);
    pre[1] = 1;
    const long long MOD = 1e9 + 7;
    for(int i = 2; i <= 200001; ++i){
        pre[i] = ((pre[i - 1] * i) % MOD);
    }
    int tt;
    cin >> tt;
    while(tt--){
        long long n;
        cin >> n;
        cout << (pre[2 * n] * 500000004) % MOD << "\n";
    }
}