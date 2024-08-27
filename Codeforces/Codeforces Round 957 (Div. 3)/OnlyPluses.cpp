#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for(int i = 0; i <= 5; ++i){
            for(int j = 0; j <= 5 - i; ++j){
                int k = 5 - i - j;
                ans = max(ans, (a + i) * (b + j) * (c + k));
            }
        }
        cout << ans << "\n";

    }
    return 0;
}
