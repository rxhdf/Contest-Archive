#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("diamond");
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int actual = 0;
        for(int j = 0; j < n; ++j){
            if(a[i] <= a[j] && a[j] <= a[i] + k)actual++;
        }
        ans = max(ans, actual);
    }
    cout << ans << "\n";
    return 0;
}