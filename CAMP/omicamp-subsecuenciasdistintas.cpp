#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> CU;
    for(auto &e: a){
        cin >> e;
        CU[e]++;
    }
    long long ans = 1;

    for(auto [a, b]: CU){
        ans = (ans * (b + 1)) % MOD;
    }

    ans = (ans - 1 + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}