#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        if(n == 1){
            cout << "-1\n";
        }else{
            cout << "2";
            for(int i = 1; i < n; ++i){
                cout << '3';
            }
            cout << "\n";
        }
    }
    return 0;
}