#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int f(int n){
    if(mp[n])return mp[n];
    if(n <= 3)return 1;
    return mp[n] = f(n - 1) + f(n - 2) + f(n - 3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << f(n) << "\n";
    return 0;
}