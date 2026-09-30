#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> pares, impares;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if((i + 1) & 1){
            impares.insert(a[i]);
        }else{
            pares.insert(a[i]);
        }
    }
    vector<int> aux = a;
    sort(aux.begin(), aux.end());
    vector<int> target(n);
    int l = 0, r = n - 1;
    for(int i = 0; i < n; ++i){
        if(i & 1){
            target[l++] = aux[i];
        }else{
            target[r-- ] = aux[i];
        }
    }
    set<int> imp, pa;
    for(int i = 0; i < n; ++i){
        if((i + 1) & 1){
            imp.insert(target[i]);
        }else{
            pa.insert(target[i]);
        }
    }
    if(imp == impares && pa == pares){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}