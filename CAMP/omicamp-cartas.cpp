#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int bg = INT32_MIN;
        for(int i = 0; i < k1; ++i){
            int x;
            cin >> x;
            bg = max(x, bg);
        }   
        for(int i = 0; i < k2; ++i){
            int x;
            cin >> x;
            if(bg < x)bg = -1;
        }
        if(bg == -1){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
    return 0;
}