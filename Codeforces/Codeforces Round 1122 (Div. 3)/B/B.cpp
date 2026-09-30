#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, int>> cnt(n);
    cnt[n - 1].first = (s[n - 1] == '0')?1: 0;
    cnt[n - 1].second = (s[n - 1] == '1')?1: 0;

    for(int i = n - 2; i >= 0; --i){
        cnt[i].first = cnt[i + 1].first + ((s[i] == '0')?1: 0);
        cnt[i].second = cnt[i + 1].first + ((s[i] == '1')?1: 0);

    }
    int ans = INT32_MAX, trans = 0;
    for(int i = 0; i < n; ++i){
        if(i == n - 1 && s[i] == '0'){
            if(trans > 0){
                ans = min(ans, trans);  
            }
        }
        if(s[i] == '1'){
            ans = min(ans, cnt[i].first + trans);
            if(i > 0){
                trans++;
            }
        }
        

    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;   
}

