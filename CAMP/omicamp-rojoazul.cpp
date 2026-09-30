#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, r, b;
        cin >> n >> r >> b;

        int base = floor(r / (b + 1));
        int reminder = r % (b + 1);

        string ans = "";
        for(int i = 0; i <= b; ++i){
            int sz = 0;
            if(i < reminder){
                sz = base + 1;
            }else{
                sz = base;
            }
            for(int j = 0; j < sz; ++j){
                ans += "R";
            }

            if(i < b)ans += "B";
        }
        cout << ans << "\n";
    }

    return 0;
}