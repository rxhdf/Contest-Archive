#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int N, K;
        cin >> N >> K;
        vector<int> A(K);
        for(auto &e: A)cin >> e;
        sort(A.begin(), A.end());
        long long int ans = 0;
        for(int i = K - 2;  i >= 0; --i){
            ans += ((A[i] - 1) * 2) + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}