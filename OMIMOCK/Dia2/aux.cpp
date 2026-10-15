#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;

    //precalcular primeras apariciones
    vector<vector<int>> precalc(n + 1, vector<int>(10, -1));
    for(int i = n - 1; i >= 0; --i){
        for(int j = 0; j <= 9; ++j){
            precalc[i][j] =  precalc[i + 1][j];
        }
        int digit = s[i] - '0';
        precalc[i][digit] = i;
    }
    
    for(int i = 0; i <= 9; ++i){
        int pos1 = precalc[0][i];
        if(pos1 == -1)continue;
        for(int j = 0; j <= 9; ++j){
            int pos2 = precalc[pos1 + 1][j];
            if(pos2 == -1)continue;
            for(int h = 0; h <= 9; ++h){
                int pos3 = precalc[pos2 + 1][h];
                if(pos3 == -1)continue;
                for(int k = 0; k <= 9; ++k){
                    int pos4 = precalc[pos3 + 1][k];
                    //se puede crear un nip (i, j, h, k)
                    if(pos4 != -1)ans++;
                }
            }
        }
    }
    cout << ans << "\n";
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