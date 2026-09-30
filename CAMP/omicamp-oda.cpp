#include <bits/stdc++.h>
#include <ios>

using namespace std;

bool compuesto(int n){
    if(n < 4)return false;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        long long sum = 0;
        cin >> n;
        vector<int> a(n);
        for(auto &e: a){
            cin >> e;
            sum += e;
        }
        int mxSize = n;
        if(!compuesto(sum)){
            for(int i = 0; i < n; ++i){
                if(a[i] & 1){
                    a[i] = -1;
                    mxSize--;
                    break;
                }
            }
        }
        
        cout << mxSize << "\n";
        for(int i = 0; i < n; ++i){
            if(a[i] != -1){
                cout << i + 1 << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}