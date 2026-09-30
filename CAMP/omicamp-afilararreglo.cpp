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
        int l = 0, r = n - 1;
        while(l < n && a[l] >= l){
            ++l;
        }
        --l;
        while(r >= 0 && a[r] >= (n - r - 1)){
            --r;
        }
        ++r;
        if(l >= r){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}