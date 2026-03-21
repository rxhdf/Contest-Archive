#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, s;
    cin >> m >> s;
    if(s == 0 && m > 1){
        cout << "-1 -1\n";
        return 0;
    }
    if(s == 0 && m == 1){
        cout << "0 0\n";
        return 0;
    }
    if (s > 9 * m) {
        cout << "-1 -1\n";
        return 0;
    }
    int aux1 = s;
    vector<int> a(m, 0), b(m, 0);

    for(int i = 0; i < m; ++i){
        if(aux1 <= 0)break;
        a[i] += min(9, aux1);
        aux1 -= 9;
    }
    b[0] = 1;
    aux1 = s - 1;
    for(int i = m - 1; i >= 0; --i){
        if(aux1 <= 0)break;
        b[i] += min(9, aux1);
        aux1 -= 9;
    }

    
    for(int i = 0; i < m; ++i){
        cout << b[i];
    }
    cout << " ";
    for(int i = 0; i < m; ++i){
        cout << a[i];
    }
    return 0;
}