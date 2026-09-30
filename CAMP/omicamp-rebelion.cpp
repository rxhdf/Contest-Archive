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
        vector<int> a(n);
        int ones = 0, ans = 0;
        for(auto &e: a){
            cin >> e;
            if(e == 1)ones++;
        }
        for(int i = n - 1; i >= 0; --i){
            if(a[i] == 0 && ones > 0){
                ans++;
            }
            ones--;
        }
        cout << ans << "\n";
    }
    return 0;
}