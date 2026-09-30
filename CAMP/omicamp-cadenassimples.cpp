#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> posA, posB;
    int L = 0, R = s.length() - 1;
    while(L < R){
        while(s[L] != '(' && L < R){
            ++L;
        }
        while(s[R] != ')' && L < R){
            --R;
        }
        if(L < R){
            posA.push_back(L + 1);
            posB.push_back(R + 1);
            ++L, --R;
        }
    }
    if(!posA.size()){
        cout << "0\n";
    }else{
        cout << "1\n" << posA.size() + posB.size() << "\n";
        for(auto e: posA){
            cout << e << " ";
        }
        reverse(posB.begin(), posB.end());
        for(auto e: posB){
            cout << e << " ";
        }
    }
    return 0;
}