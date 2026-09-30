#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
ll x, y, m, ans = 0;

int main() {
    setIO("pails");
    cin >> x >> y >> m;
    for(int i = 0; i * x <= m; ++i){
        for(int j = 0; j * y + x * i <= m; ++j){
            ans = max(ans, j * y + x * i);
        }
    }
    cout << ans << "\n";
    return 0;
}