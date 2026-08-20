#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int diagonales(int lados){
    if(lados == 4)return 2;
    for(int i = 1; i < lados; ++i){
        return diagonales(lados - 1);
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << diagonales(5);
    return 0;
}