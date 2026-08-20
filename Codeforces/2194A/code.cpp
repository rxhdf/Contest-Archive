#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    cout << a - (a / b) << "\n";
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