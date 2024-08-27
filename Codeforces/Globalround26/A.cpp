#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; ++i){
            cin >> A[i];
        }
        if(A[0] == A[N - 1]){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            string s(N, 'R');
            s[1] = 'B';
            cout << s << "\n";
        }
    }
    return 0;
}