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
        vector<int> a( 2 * n);
        for(auto &e: a){
            cin >> e;
        }
        sort(a.begin(), a.end());

        cout << abs(a[n] - a[n - 1]) << "\n";
    }

    return 0;
}