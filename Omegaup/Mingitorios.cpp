#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(auto &e: a){
        cin >> e;
    }
    long long ans = 0, mayor = 0;
    bool ok = false;
    for(auto &e: a){
        mayor = max(mayor, e);
        if(e > k){
            ans += k;
            ok = true;
        }else{
            ans += e;
        }
    }
    if(ok)cout << ans << "\n";
    else cout << ans + abs(mayor - k) << "\n";
    
    return 0;
}