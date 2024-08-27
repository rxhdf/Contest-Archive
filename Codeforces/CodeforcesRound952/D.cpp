#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int N, M;
        cin >> N >> M;
        vector<vector<char>> A(N + 1, vector<char>(M + 1,'.'));
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                cin >> A[i][j];
            }
        }
        pair<int, int> PX, PY;
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                if(A[i][j] == '#'){
                    PX = min(PX, {i, j});
                    PY = max(PY, {i, j});
                }
            }
        }
        assert(PX.second == PY.second);
        cout << (PX.first + PY.first) / 2 + 1 << " " << PX.second << "\n";
    }
    return 0;
}