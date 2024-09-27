#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#define MAX (int)1e6 + 4
using namespace std;

long long int N, op = 0, itr = 0;
string S, R;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cin >> S;
    reverse(S.begin(), S.end());
    R = S;
    while(itr < N - 1){
        if(R[itr] == '0'){
            int aux = itr;
            while(R[itr] == '0'){

            }
        }
    }
    cout << op << "\n";
    return 0;
}