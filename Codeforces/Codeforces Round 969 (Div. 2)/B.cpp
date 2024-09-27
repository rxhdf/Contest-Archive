#include <bits/stdc++.h>
#define ll long long int
#define number first
#define position second

using namespace std;

void solve(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0);
    vector<pair<int, int>> B(N, {0, 0});
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        B[i] = make_pair(A[i], i);
    }
    sort(B.begin(), B.end());
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }

    return 0;
}