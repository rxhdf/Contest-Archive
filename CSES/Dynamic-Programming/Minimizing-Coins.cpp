#include <bits/stdc++.h>
 
#define optimizaIO() ios_base::sync_with_stdio(0);cin.tie(0);
#define INF INT32_MAX
 
using namespace std;
 
int main(){
    optimizaIO();
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for(auto &e: A)cin >> e;
    vector<int> DP(X+1, 1e9);
    DP[0] = 0;
    for(int i = 1; i <= X; ++i){
        for(int j = 0; j < N; ++j){
            if(i - A[j] >= 0){
                DP[i] = min(DP[i], DP[i-A[j]] + 1);
            }
        }
    }
    if(DP[X] == 1e9)cout << "-1\n";
    else cout << DP[X] << "\n";
    return 0;
}

