#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e: a){
        cin >> e;
    }
    sort(a.rbegin(), a.rend());
    if(a[0] >= a[1] + a[2]){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        for(auto e: a){
            cout << e << " ";
        }
    }
    
    return 0;
}