#include <bits/stdc++.h>

using namespace std;

 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &e: A)cin >> e;
    vector<int> DP(N, INT32_MAX);
    for(int i = 0; i < N; ++i){
        for(int j = 1; j <= K; ++j){
            if(i + j < N){
                DP[i + j] = min(DP[i + j], DP[i] + abs(A[i] - A[i + j]));
            }
        }
    }
    cout << DP[N - 1] << "\n";
    return 0;
 }