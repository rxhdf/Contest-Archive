#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string op1 = rev + s;
        string op2 = s + rev;
        if(op1 == op2 || k == 0){
            cout << "1\n";
        }else{
            cout << "2\n";
        }
    }

    return 0;
}