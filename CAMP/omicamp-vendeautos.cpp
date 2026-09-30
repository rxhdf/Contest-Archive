#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, x;
        cin >> n >> x;
        long long sum = 0, mxn = INT32_MIN;
        for(int i = 0; i < n; ++i){
            long long a;
            cin >> a;
            sum += a;
            mxn = max(mxn, a);
        }
        long long ans1 = (sum + x - 1) / x;

        long long ans = max(ans1, mxn);
        cout << ans << "\n";
    }
    return 0;
}