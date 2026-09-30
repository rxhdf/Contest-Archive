#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<long long> a(n);
        long long mx = INT32_MIN;
        for(auto &e: a){
            cin >> e;
            mx = max(e, mx);
        }
        bool found = false;
        for(int i = 0; i < n; ++i){
            if(a[i] < 0 && !found){
                cout << a[i] << "\n";
                found = true;
            }
        }
        if(!found){
            cout << mx << "\n";
        }
    }


    return 0;
}