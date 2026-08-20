#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> ans(3*n, 0);
        int cnt1 = 1, cnt2 = n, cnt3 = 2 * n;
        for(int i = 0; i < 3 * n; i += 3){
            ans[i] = cnt1;
            ans[i + 1] = cnt2;
            ans[i + 2] = cnt3;
            cnt1++, cnt2++, cnt3++;
        }
        for(auto e: ans)cout <<e << " ";
        cout << "\n";
    }

    return 0;
}