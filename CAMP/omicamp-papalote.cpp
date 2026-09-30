#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mt(n, vector<int>(m));
    vector<int> row_sum(n, 0), col_sum(m, 0);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mt[i][j];
            row_sum[i] += mt[i][j];
            col_sum[j] += mt[i][j];
        }
    }

    vector<int> f, c;
    bool ok = true;
    while(ok){
        ok = false;
        for(int i = 0; i < n; ++i){
            if(row_sum[i] < 0){
                f.push_back(i + 1);
                row_sum[i] = -1 * row_sum[i];
                for(int j = 0; j < m; ++j){
                    col_sum[j] -= 2 * mt[i][j];
                    mt[i][j] = -1 * mt[i][j];
                }
                ok = true;
                break;
            }
        }
        if(ok)continue;
        for(int i = 0; i < m; ++i){
            if(col_sum[i] < 0){
                c.push_back(i + 1);
                col_sum[i] = -1 * col_sum[i];
                for(int j = 0; j < n; ++j){
                    row_sum[j] -= 2 * mt[j][i];
                    mt[j][i] = -1 * mt[j][i];
                }
                ok = true;
                break;
            }
        }
    }






    cout << f.size() << " ";
    for(auto e: f){
        cout << e << " ";
    }
    cout << "\n";
    cout << c.size() << " ";
    for(auto e: c){
        cout << e << " ";
    }
    return 0;
}