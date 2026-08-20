#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, fst = 0, ans = 0, x;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if(!i){
            fst = x;
        }
        if(x < fst)ans++;
    }
    cout << ans << "\n";
    return 0;
}