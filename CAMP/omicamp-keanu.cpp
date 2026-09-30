#include <bits/stdc++.h>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> buenos(n, false);
    int zeros, ones;
    zeros = ones = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            ones++;
        }else{  
            zeros++;
        }

        if(ones != zeros){
            buenos[i] = true;
        }
    }
    zeros = ones = 0;
    int pt = 0;
    for(int i = n - 1; i > 0; --i){
        if(s[i] == '1'){
            ones++;
        }else{  
            zeros++;
        }
        if(ones != zeros && buenos[i - 1]){
            pt = i - 1;
        }
    }
    if(n == 1  || buenos[n - 1]){
        cout << "1" << "\n" << s << "\n";
    }else{
        cout << "2" << "\n";
        for(int i = 0; i <= pt; ++i){
            cout << s[i];
        }
        cout << " ";
        for(int i = pt + 1; i < n; ++i){
            cout << s[i];
        }
        cout << "\n";
    }
    return 0;
}