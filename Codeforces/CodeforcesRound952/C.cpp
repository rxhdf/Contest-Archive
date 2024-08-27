#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int N;
        cin >> N;
        vector<ll> A(N+1), Prefix(N+1, 0), MAX(N+1, 0);
        for(int i = 1; i <= N; ++i){
            cin >> A[i];
            Prefix[i] = Prefix[i-1] + A[i];
            MAX[i] = max(MAX[i-1], A[i]);
        }
        int ans = 0;
        for(int i = 1; i <= N; ++i){
            ll S = Prefix[i] - MAX[i];
            if(S == MAX[i])ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}