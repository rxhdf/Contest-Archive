#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int N, M, L, Matrix[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> L;
    memset(Matrix, 0, sizeof(Matrix));
    while(L--){
        int x, y;
        cin >> x >> y;
        Matrix[x][y] = 1;
    }   
    int ans = 0;
    for(int i = 1; i < N; ++i){
        for(int j = 1; j < M; ++j){
            if(!Matrix[i][j] && !Matrix[i][j + 1] && !Matrix[i + 1][j] && !Matrix[i + 1][j + 1])ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}