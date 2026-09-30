#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        string s;
        cin >> s;
        int one = 0, zero = 0;
        bool xfound = false;
        for(auto e: s){
            if(e == '0'){
                if(!xfound){
                    zero++;
                    xfound = true;
                }
            }else{
                xfound = false;
            }
        }
        if(zero == 0){
            cout << "0\n";
        }
        else if(zero == 1){
            cout << "1\n";
        }else{
            cout << "2\n";
        }
    }
    return 0;
}