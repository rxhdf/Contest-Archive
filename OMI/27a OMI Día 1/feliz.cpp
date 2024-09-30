#include <bits/stdc++.h>
#define MAX (int)1e5 + 5
using namespace std;

int T, Q;
string S;
vector<int> P(MAX, 0);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> Q >> S;
    for(int i = 1; i < T; ++i){
        P[i] = P[i - 1] + (S[i] == S[i - 1]? 1: 0);
    }
    //for(int i = 0; i < T; ++i)cout << P[i] << " ";

    while(Q--){
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << P[r] - P[l] << "\n";
    }
    return 0;
}