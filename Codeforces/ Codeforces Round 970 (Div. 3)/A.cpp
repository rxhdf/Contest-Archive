#include <bits/stdc++.h>
#define ll long long int
#define number first
#define position second

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    
    if(a == 0 || b == 0){
        if(a == 0 && b % 2 == 0){
            cout << "YES\n";
            return;
        }
        else if(b == 0 && a % 2 == 0){
            cout << "YES\n";
            return;
        }
    }
    else if(a % 2 == 0){
            if(a% 2 == 0 || b == 1){
                cout << "YES\n";    
                return;
            }
    }
    cout << "NO\n";
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