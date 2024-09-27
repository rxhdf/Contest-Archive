#include <bits/stdc++.h>

using namespace std;

int N, K;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    vector<int> A(N + 1, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            cout << " {" << A[j] + abs(j - i) << "} - {diference, i, j, " << abs(j - i) << " - " << j << " - " << i << "}";
        }
        cout << "<<<\n";
    }
    return 0;
}