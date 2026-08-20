#include <bits/stdc++.h>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, ans = 0;
        cin >> n;
        if(n == 2)cout << "2\n";
        else if(n == 3)cout << "3\n";
        else{
            if(n & 1){
                cout << "1\n";
            }else{
                cout << "0" << "\n";
            }
        }
    }
    return 0;
}