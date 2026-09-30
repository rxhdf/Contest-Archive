// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), pos(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] != (i + 1)){
            int aux = a[i];
            swap(a[i], a[pos[i + 1]]);
            swap(pos[i + 1], pos[aux]);
            ans++;
        }
    }
    cout << ans << "\n";

}

int main() {
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
