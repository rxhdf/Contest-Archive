#include <algorithm>
#include <bits/stdc++.h>
#define MAX (int)1e6 + 4
using namespace std;

int N, M;
vector<int> A(MAX, 0), V(MAX, 0);
set<int> L;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    for(int i = 1; i <= M; ++i){
        cin >> V[i];
        L.insert(V[i]);
    }
    sort(V.begin(), V.end());
    for(int i = 1; i < N; ++i){
        
    }
    return 0;
}