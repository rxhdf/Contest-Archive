#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> N;
    vector<int> A(N);
    for(auto &e: A)cin >> e;
    sort(A.begin(), A.end());
    ll ans = 0;
    for(int i = 0; i < N; ++i){
        ans += abs(A[i] - A[N/2]);
    }
    cout << ans << "\n";
    return 0;
}