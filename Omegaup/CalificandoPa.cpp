#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int val1 = 0, val2 = 0;
    for(int i = 0; i < a.size(); ++i){
        if(isdigit(a[i])){
            val1 += a[i] - '0';
        }else{
            if((int)a[i] > 90){
                val1 += ((int)a[i] - 97) + 10;
            }else{
                val1 += (((int)a[i] - 65) * 2) + 20;
            }
        }
    }   
    for(int i = 0; i < b.size(); ++i){
        if(isdigit(b[i])){
            val2 += b[i] - '0';
        }else{
            if((int)b[i] > 90){
                val2 += ((int)b[i] - 97) + 10;
            }else{
                val2 += (((int)b[i] - 65) * 2) + 20;
            }
        }
    }
    if(val1 > val2){
        cout << "Ana " << val1 << "\n";
    }else{
        cout << "Carolina " << val2 << "\n";
    }
    return 0;
}