#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string S;
    getline(cin, S);
    int flag = 0;
    list<string> L;
    for(int i = 0; i < S.length(); ++i){
        if(S[i] == '[')flag--;
        else if(S[i] == ']')flag++;
        else{
            if(flag >= 0){
                string n;
                while(S[i] != '[' && S[i] != ']' && S[i] != ' ' && i < S.length()){
                    n += S[i];
                    ++i;
                }
                L.push_back(n);
            }else{
                string n;
                while(S[i] != '[' && S[i] != ']' && i < S.length()){

                    n += S[i]; 
                    if(S[i] == ' ')break;
                    ++i;
                    
                }
                L.push_front(n);
            }
        }
    }
    for(auto &e: L)cout << e;
    return 0;
}