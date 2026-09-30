#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        string s;
        cin >> n >> k >> s;
        bool ok = true;
        int consecutives = 0;
        for(auto c: s){
            if(c == '1'){
                consecutives++;
                if(consecutives >= k)ok = false;
            }else{
                consecutives = 0;
            }
        }
        if(!ok){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<int> perm(n);
        int value = n;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                perm[i] = value;
                value--;
            }
            
        }
        for(int i = 0; i < n; ++i){
            if(s[i] == '1'){
                perm[i] = value;
                value--;
            }
            
        }
        for(int i = 0; i < n; ++i){
            cout << perm[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
