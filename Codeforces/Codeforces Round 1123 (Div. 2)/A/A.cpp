#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    char c;
    cin >> n >> c;
    int l = 0, r = n - 1;
    int ans = 0;
    string s;
    cin >> s;
    while(l < r){
        if(s[l] != s[r]){
            if(s[l] != c){
                ++ans;
            }
            if(s[r] != c){
                ++ans;
            }
        } 
        ++l, --r;
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