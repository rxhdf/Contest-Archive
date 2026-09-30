#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        //cout << "CASE\n";
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        long long positivos = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] > 0){
                positivos += a[i];
                a[i] = 0;
            }

            if(a[i] < 0){
                if(-a[i] > positivos){
                    a[i] += positivos;
                    positivos = 0;
                    
                }else{
                    positivos += a[i];
                    a[i] = 0;
                }
            }
            //cout << positivos << "Liberalismo\n";
        }
        for(auto e: a){
            ans += -e;
        }
        cout << ans << "\n";
    }

    return 0;
}