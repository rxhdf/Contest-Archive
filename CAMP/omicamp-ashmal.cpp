#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<string> s(n);
        for(auto &e: s){
            cin >> e;
        }
        string ans = s[0], primero = s[0];
        for(int i = 1; i < n; ++i){
            if(ans + s[i] > s[i] + ans){
                ans = s[i] + ans;
            }else{
                ans = ans + s[i];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}