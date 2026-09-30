#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    int one, two, en;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] == 1){
            one = i;
        }
        else if(a[i] == 2){
            two = i;
        }
        else if(a[i] == n){
            en = i;
        }   
    }
    if(en >= min(two, one) && en < max(two, one)){
        cout << "1 1\n";
    }else{
        if(en < min(two, one)){
            cout << en << " " << min(two, one) << "\n";
        }
        else if(en > max(two, one)){
            cout << en << " " << max(two, one) << "\n";
        }
    }   
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