#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    vector<int> a(n + 1, 0), pr(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pr[i] = pr[i - 1] + a[i];
    }
    cin >> q;
    while(q--){
        int l, r;
        long long ans = 0, prfs = 0;
        cin >> l >> r;
        map<int, int> prfx;
        for(int i = l - 1; i <= r; ++i){
            ans += prfx[pr[i] - i]; 
            prfx[pr[i] - i]++;        
        }
        cout << ans << "\n";
    }
    return 0;
}