#include <bits/stdc++.h>
using namespace std;



//x = target
//n = monedas
//a[i] = valor de moneda i
int f(int suma_actual){
    if(suma_actual == x)return 1;
    if(suma_actual > x)return 0;
    for(int i = 0; i < n; ++i){
        return f(suma_actual + a[i]) + f(suma_actual);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &e : a){
        cin >> e;
    }
    
    return 0;
}
