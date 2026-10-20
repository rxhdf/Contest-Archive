#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int cnt = 1;
    for(int i = 1; i < (int)s.length() - 1; ++i){
        while(s[i] == s[i - 1]){
            ++i;
        }
        cnt++;
    }
    cout << cnt << "\n";
}

//7 3
//001
//000
//101
//100



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