#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--){
        int A[100], cnt[100];
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i){
            cin >> A[i];
            cnt[A[i]]++;
        }
        for(int i = 50; i >= 1; --i){
            cnt[i] += cnt[i + 1];
            if(cnt[i] % 2 == 1){
                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";
    }

    return 0;
}
