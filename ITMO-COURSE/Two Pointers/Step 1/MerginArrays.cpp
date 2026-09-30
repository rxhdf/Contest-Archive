#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    //Leer Entrada
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int j = 0; j < m; ++j){
        cin >> b[j];
    }
    a.push_back(INT32_MAX);
    b.push_back(INT32_MAX);
    int i = 0, j = 0;
    while(i < n || j < m){
        if(a[i] < b[j]){
            cout << a[i] << " ";
            ++i;
        }else{
            cout << b[j] << " ";
            ++j;
        }
    }
    cout << "\n";
    return 0;
}