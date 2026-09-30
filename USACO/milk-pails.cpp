#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("pails");
    int x, y, m;
    cin >> x >> y >> m;
    ll ans = 0;
    int timesx = m / x, timesy = m / y;
    for(int i = 0; i <= timesx; ++i){
        for(int j = 0; j <= timesy; ++j){
            int total = (j * y) + (i * x);
            ans = max(ans, (ll)((total <= m)? total: 0));
        }
    }
    cout << ans << "\n";
    return 0;
}