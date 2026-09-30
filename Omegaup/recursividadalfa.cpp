#include <bits/stdc++.h>
using namespace std;

map<long long, long long> mp;

long long f(int n){
    if(mp[n])return mp[n];
    if(n < 50)return 2;
    return mp[n] = f(n - 1) + (f(n - 5) * 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << f(n) << "\n";
    return 0;
}