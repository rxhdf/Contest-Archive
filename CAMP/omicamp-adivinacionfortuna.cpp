#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        long long n, x, y;
        cin >> n >> x >> y;
        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            x += a;
        }
        if((x & 1) == (y & 1)){
            cout << "Alice\n";
        }else{
            cout << "Bob\n";
        }
    }
    return 0;
}