#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N), DP(N, INT32_MAX);
    for(auto &e: A)cin >> e;
    DP[0] = 0;

    for(int i = 0; i < N - 1; ++i){
        if(i + 1 < N){
            DP[i + 1] = min(DP[i + 1], DP[i] + abs(A[i] - A[i + 1]));
        }
        if(i + 2 < N){
            DP[i + 2] = min(DP[i + 2], DP[i] + abs(A[i] - A[i + 2]));
        }
    }
    cout << DP[N - 1] << "\n";
    return 0;
}