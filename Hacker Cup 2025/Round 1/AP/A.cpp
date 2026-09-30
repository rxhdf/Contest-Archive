#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); 
    //freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("");
    int tt, i = 1;
    cin >> tt;
    while(i <= tt){
        int n;
        cin >> n;
        int ans = 0;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 1; i < n; ++i){
            ans = max(abs(a[i] - a[i - 1]), ans);
        }
        cout << "Case #" << i << ": " << ans << "\n";
        ++i;
    }
    return 0;
}