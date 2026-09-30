// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntt = 0, cntm = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'T'){
            cntt++;
        }else{
            cntm++;
        }
    }
    if(cntt != 2 * cntm){
        cout << "NO\n";
        return;
    }

    int tAcum = 0, mAcum = 0;
    //prefijo
    for(int i = 0; i < n; ++i){
        if(s[i] == 'T'){
            tAcum++;
        }else{
            mAcum++;
        }
        if(mAcum > tAcum){
            cout << "NO\n";
            return;
        }
    }
    tAcum = 0, mAcum = 0;
    for(int i = n - 1; i >= 0; --i){
        if(s[i] == 'T'){
            tAcum++;
        }else{
            mAcum++;
        }
        if(mAcum > tAcum){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
