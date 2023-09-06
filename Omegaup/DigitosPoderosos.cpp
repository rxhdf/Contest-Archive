#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        string x; 
        unsigned long int y, next = 0;
        cin >> x >> y;
        for(int i = 0; i < (int)x.size(); ++i){
            next += x[i]  - '0';
        }
        unsigned long int k = 0;
        while(next > 9){
            k = 0;
            while(next > 0){
                int now = next % 10;
                next /= 10;
                k+=now;
            }
            next = k;
        }
        next *= y;
        while(next > 9){
            k = 0;
            while(next > 0){
                int now = next % 10;
                next /= 10;
                k+=now;
            }
            next = k;
        }
        cout << next <<  "\n";
    }
    return 0;
}