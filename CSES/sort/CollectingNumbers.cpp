#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        mp[a[i]] = i;
    }
    int ans = 1;
    for(int i = 1; i < n; ++i){
        if(mp[i] > mp[i + 1])ans++;
        //cout << mp[i] << " " << mp[i + 1];
    }
    cout << ans << "\n";
    return 0;
}