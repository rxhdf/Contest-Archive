#include <bits/stdc++.h>
#include <ios>
#define ll long long int

using namespace std;

bool ispalindrome(string S){
    for(int i = 0, j = S.length() - 1; i <= j; ++i, --j){
        if(S[i] != S[j])return false;
    }
    return true;
}

string Base(int A, int c){
    string S;

    while(A > 0){
        int x = A % c;
        A /= c;
        S += x + '0';
    }
    //S += A + '0';
    return S;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll A;
    cin >> A;
    for(int i = 2; i <= 10; ++i){
        string S = Base(A, i);
        if (ispalindrome(S)){
            reverse(S.begin(), S.end());
            cout << i << " " << S << "\n";
            return 0;
        }
    }
    cout << -1 << " 0" << "\n";
    return 0;
}