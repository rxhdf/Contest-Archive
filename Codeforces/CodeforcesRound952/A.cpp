#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        string A, B;
        cin >> A >> B;
        cout << B[0];
        for(int i = 1; i < A.size(); ++i)cout << A[i];
        cout << " ";
        cout << A[0];
        for(int i = 1; i < B.size(); ++i)cout << B[i];
        cout << "\n";
    }
    return 0;
}