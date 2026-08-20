#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((max(a, b) <= 2 * (min(a, b) + 1)) && (max(c - a, d - b) <= 2 * (min(c - a, d - b) + 1))){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}