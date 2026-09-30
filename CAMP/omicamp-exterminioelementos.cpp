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
        vector<int> a(n);
        for(auto &e: a){
            cin >> e;
        }
        if(a[0] < a[n - 1]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}