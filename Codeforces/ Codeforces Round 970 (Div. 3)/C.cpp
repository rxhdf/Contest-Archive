
#include <bits/stdc++.h>
#define ll long long int 

using namespace std;

void solve(){
    ll l, r;
    cin >> l >> r;
    r-=l;
    ll low = 2, high = 1000000000, mid, ans;
    while(low < high){
        mid = (low + high) / 2;
        ans = ((mid * (mid - 1)) / 2);
        if(ans <= r){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    cout << low - 1 << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}