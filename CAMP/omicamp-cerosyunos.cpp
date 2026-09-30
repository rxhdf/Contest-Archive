#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<char> zeros, ones;

    int op = 0;

    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            if(ones.empty()){
                zeros.push('0');
            }else{
                op++;
                ones.pop();
            }
        }else{
            if(zeros.empty()){
                ones.push('1');
            }else{
                op++;
                zeros.pop();
            }
        }
    }
    cout << n - (2 * op) << "\n";
    return 0;
}