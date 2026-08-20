#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, twos = 0, ones = 0, zeros = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] == 2){
            ones++;
        }
        else if(a[i] == 1){
            twos++;
        }else{
            zeros++;
        }
            
    }
    int ans = min(twos, ones);
    twos -= ans;
    ones -= ans;

    if(twos > 0){
        ans += ((twos * 2) / 6);
    }else{
        ans += (ones / 3);
    }
    
    cout << ans + zeros << "\n";
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