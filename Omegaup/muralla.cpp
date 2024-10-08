#include <bits/stdc++.h>
#include <ios>

using namespace std;

string S;

bool validate(deque<char> A, deque<char> B){
    /*for(int i = 0, k = 0; i < S.length(); ++i, ++k){
        if(k == CP.length())k = 0;
        if(CP[k] == S[i])continue;
        else return false;
    }*/    
    /*for (int i = 0; i < S.length(); i += CP.length()) {
        if (i + CP.length() > S.length()) {
            if (CP.substr(0, S.length() - i) == S.substr(i, S.length() - i)) {
                return true;
            } else {
                return false;
            }
        }
        if (S.substr(i, CP.length()) == CP) continue;
        else return false;
    }
    return true*/

    /*for (int i = 0; i < S.length(); i += CP.length()) {
        if (S.length() - i < CP.length()) {
            return S.substr(i, S.length() - i) == CP.substr(0, S.length() - i);
        }

        if (S.substr(i, CP.length()) != CP) return false;
    }
    
    return true;*/
    if(A.size() > B.size()){
        for(int i = 0; i < A.size(); ++i){
            if(A[i] != B[i % B.size()])return false;
        }
        return true;
    }else{
        for(int i = 0; i < A.size(); ++i){
            if(A[i] != B[i])return false;
        }
        return true;
    }

}
bool same(string S){
    for(int i = 0, j = S.length() - 1; i <= j; ++i, --j){
        if(S[i] != S[j])return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    //get the actual length
    /*
    string copi;
    for(int i = 0; i < S.length(); ++i){
        copi += S[i];
        if(validate(copi)){
            cout << i + 1 << "\n";
            break;
        }
        //cout << copi << "\n";
    }*/
    deque<char> A, B;
    for(int i = 0; i < S.length(); ++i){
        A.push_back(S[i]);
    }
    if(same(S)){
        cout << 1 << "\n";
    }else{
        while(!A.empty()){
            B.push_back(A.front());
            A.pop_front();
            if(validate(A, B)){
                cout << B.size() << "\n";
                break;
            }
        }
    }   
    return 0;
}