#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int j = 0; j < m; ++j){
        cin >> b[j];
    }
    a.push_back(INT32_MAX);
    int j = 0;
    for(int i = 0; i < m; ++i){
        while(a[j] < b[i]){
            ++j;
        }
        cout << j << " ";
    }    
    return 0;
}