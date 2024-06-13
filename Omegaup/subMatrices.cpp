#include <bits/stdc++.h>
#define MAX (int)1002
using namespace std;

int N, M, r, c;
vector<vector<int>> MT(MAX, vector<int>(MAX, 0)); 
vector<vector<bool>> ans(MAX, vector<bool>(MAX, 0));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> MT[i][j];
        }
    }
    cin >> r >> c;
    vector<vector<int>> SM(r + 1, vector<int>(c + 1, 0));
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            cin >> SM[i][j];
        }
    }
    for(int i = 1; i <= N - r + 1; ++i){
        for(int j = 1; j <= M - c + 1; ++j){
            bool flag = true;
            for(int k = 1; k <= r && flag; ++k){
                for(int l = 1; l <= c && flag; ++l){
                    if(MT[k + i - 1][l + j - 1] != SM[k][l]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                for(int k = i; k < r + i; ++k){
                    for(int l = j; l < c + j; ++l){
                        ans[k][l] = 1;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}