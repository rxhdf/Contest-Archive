#include <bits/stdc++.h>

using namespace std;

int c(const string &S){
    if(S.length() == 0)return 0;
    int time = 2;
    for(int i = 1; i < S.length(); ++i){
        if(S[i] == S[i - 1]){
            time += 1;
        }else{
            time += 2;
        }
    } 
    return time;
}

string solve(const string &S){
    string Best = S;
    int MX = c(S);
    for(int i = 0; i <= S.length(); ++i){
        for(char j = 'a'; j <= 'z'; ++j){
            string nw = S.substr(0, i) + j + S.substr(i);
            int nwt = c(nw);
            if(nwt > MX){
                MX = nwt;
                Best = nw;
            }
        }
    }
    return Best;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    vector<string> A;
    while(tt--){
        string S;
        cin >> S;
        cout << solve(S) << "\n";
    }
    return 0;
}

