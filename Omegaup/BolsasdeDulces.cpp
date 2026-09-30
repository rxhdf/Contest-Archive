#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        ans += (a * b);
    }
    cout << ans << "\n";
    return 0;
}