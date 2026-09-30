#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    map<int, int> mp;
    mp[0] = 1;
    int pr = 0, ans = 0;
    for(int i = 0; i < n; ++i){
        pr ^= a[i];
        ans += mp[pr];
        mp[pr]++;
    }
    cout << ans << "\n";
    return 0;
}