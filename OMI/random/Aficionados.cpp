#include <bits/stdc++.h>
#include <ios>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    if(N == 2){
        cout << "-1\n";
        return 0;
    }
    for(int i = 1; i < N - 1; ++i){
        if(A[i] == A[i - 1]){
            cout << i << " " << i - 1 << "\n";
            return 0;
        }
        if(A[i] == A[i + 1] ){
            cout << i << " " << i + 1 << "\n";
            return 0;
        }
        if(A[i - 1] == A[i + 1]){
            cout << i - 1 << " " << i + 1 << '\n';
            return 0;
        }

    }

    cout << "-1\n";

    return 0;
}