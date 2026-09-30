#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mxmans = 0, mnans = 0, l = 0, r = n - 1;
    for(int i = 0; i < n; ++i){
        mnans += abs(a[i] - b[i]);
        mxmans += abs(a[l] - b[r]);
        l++, r--;
    }
    cout << mnans << " " << mxmans << "\n";
    return 0;
}