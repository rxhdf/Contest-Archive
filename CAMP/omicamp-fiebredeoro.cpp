#include <bits/stdc++.h>

using namespace std;

long long n, m;
bool found;
void can(long long x, long long m){
    //cout << x << "x actual " << m << "\n" ;
    if(x == m)found = true;
    if(x <= 0 || x % 3 != 0){
        return;
    }
    can(x/3, m);
    can(2*(x/3), m);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        found = false;
        cin >> n >> m;
        can(n, m);
        if(found){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}