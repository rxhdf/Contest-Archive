#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    //grupo, 0, 1
    map<int, pair<int, int>> groups;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < k; ++i){
        for(int j = i; j < n; j += k){
            if(s[j] == '0'){
                groups[i].first++;
            }
            else if(s[j] == '1'){
                groups[i].second++;
            }
        }
        if(groups[i].first > 0 && groups[i].second > 0){
            cout << "NO\n";
            return;
        }
        else if(groups[i].first > 0){
            cnt1++;
        }
        else if(groups[i].second > 0){
            cnt2++;
        }
    }
    if(cnt1 > (k / 2) || cnt2 > (k / 2)){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}