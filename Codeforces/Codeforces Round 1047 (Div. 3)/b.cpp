#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--){
        long long a,b;
        cin >> a >> b;
        if( (a + b) % 2 == 0 ){
            cout << (a + b) << '\n';
            continue;
        }
        if(b % 2 == 1){
            cout << -1 << '\n';
            continue;
        }
        int g = 0;
        long long tmp = b;
        while((tmp & 1LL) == 0){
            tmp >>= 1;
            ++g;
        }
        if(g <= 1){
            cout << -1 << '\n';
        } else {
            cout << (a * (b / 2) + 2) << '\n';
        }
    }
    return 0;
}
