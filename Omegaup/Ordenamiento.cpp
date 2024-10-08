#include <bits/stdc++.h>

using namespace std;

void solve(){
    string S;
    cin >> S;
    stack<char> A;
    int Msize = 0, LI = 0, actualZ = 0;
    for(int i = 0; i < S.length(); ++i){
        if(S[i] == '('){
            A.push(S[i]);
            actualZ++;
        }
        
    }   
    cout << Msize << " " << LI << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(nullptr);
    //int tt;
    //cin >> tt;
    //while(tt--)
        solve();

    return 0;
}