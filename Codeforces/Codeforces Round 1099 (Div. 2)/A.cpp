#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, aux = 1;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cout << aux << " ";
        aux += 2;
    }

    cout << "\n";
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