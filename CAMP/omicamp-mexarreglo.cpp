#include <bits/stdc++.h>

using namespace std;

int mex(vector<int> const& A) {
    set<int> b(A.begin(), A.end());
    int result = 0;
    while(b.count(result)){
        ++result;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        //cout << "Caso\n";
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        int ans = 0;
        for(int l = 0; l < n; ++l){
            for(int r = l; r < n; ++r){
                vector<int> aux;
                aux.assign(a.begin() + l, a.begin() + (r + 1));
                //cout << "Subsegmento \n";
                for(int i = 0; i < aux.size(); ++i){
                    //cout << aux[i] << " ";
                    ans += mex({aux[i]});
                }
                ans += r - l + 1;
                //cout << "\n";
               // cout << 1 << " " << mex(aux) << "\n";
            }
        }
        cout << ans << "\n";
    }

    return 0;
}