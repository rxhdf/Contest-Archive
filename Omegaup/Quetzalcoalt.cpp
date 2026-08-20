#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), s(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    int gMax = 0;
    for(int i = 0; i < n; ++i){
        int dMax = 0;
        for(int j = i; j >= 0; --j){
            if(a[j] <= 0)continue;
            dMax += min(a[j], s[i]);
            a[j] -= s[i];
        }
        gMax = max(dMax, gMax);
        //cout << dMax << "\n";
    }
    cout << gMax << "\n";
    return 0;
}