#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        int a[n][n];
        int cnt = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                a[i][j] = cnt;
                cnt++;
            }
        }
        if(n == 1)cout << "1\n";
        else if(n == 2)cout << "9\n";
        else {
            cout << max((a[n - 1][n - 1] + a[n - 1][n - 2] + a[n - 1][n - 3] + a[n - 2][n - 2]), a[n - 2][n - 1] + a[n - 2][n - 2] + a[n - 2][n - 3] + a[n - 3][n - 2] + a[n - 1][n - 2]) << "\n";
        }
    }
    return 0;
}