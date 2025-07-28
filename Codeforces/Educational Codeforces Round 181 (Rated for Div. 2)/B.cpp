#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        long long a, b, k;
        cin >> a >> b >> k;
        if(k >= a && k >= b){
            cout << "1\n";
        }
        else if(__gcd(a, b) < k){
            if(a == b || __gcd(a, b) != 1){
                cout << "1\n";
                continue;
            }else{
                cout << "2\n";
                continue;
            }
        }else{
            cout << "2\n";
       }
    }
    return 0;
}