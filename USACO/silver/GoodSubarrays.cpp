#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> prf(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            char x;
            cin >> x;
            prf[i] = prf[i - 1] + x - '0';
        }   
        //for(auto e: prf)cout << e << " ";
        //cout << "\n";
        ll ans = 0;
        map<int, int> prfx;
        for(int i = 0; i <= n; ++i){
            ans += prfx[prf[i] - i];
            prfx[prf[i] - i]++;
        }
        cout << ans << "\n";
    }
    return 0;
}