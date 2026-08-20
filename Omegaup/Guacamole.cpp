#include <bits/stdc++.h>
#define ll long long
using namespace std;

int isAvailable(int i, int j, int time, vector<vector<int>> &first, vector<vector<int>> &repeat){
    if(time < first[i][j]) return 0;
    if(repeat[i][j] == 0) return (time == first[i][j]) ? 1 : 0;
    return ((time - first[i][j]) % repeat[i][j] == 0) ? 1 : 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    cin >> n >> m >> t;
    
    vector<vector<int>> I(n, vector<int>(m)), P(n, vector<int>(m)), S(n, vector<int>(m));
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(t+1, 0)));
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1, 0};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1, 0};
    
    // Leer inputs
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> I[i][j];
            
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> P[i][j];
            
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> S[i][j];
    
    // Inicializar tiempo 0
    for(int j = 0; j < n; j++){
        for(int k = 0; k < m; k++){
            dp[j][k][0] = isAvailable(j, k, 0, I, S) * P[j][k];
        }
    }
    
    ll answer = 0;
    for(int time = 1; time <= t; time++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ll maxPrev = 0;
                for(int d = 0; d < 9; d++){
                    int ni = i + dx[d], nj = j + dy[d];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                        maxPrev = max(maxPrev, dp[ni][nj][time-1]);
                    }
                }
                dp[i][j][time] = maxPrev + (isAvailable(i, j, time, I, S) * P[i][j]);
                answer = max(answer, dp[i][j][time]);
            }
        }
    }
    
    cout << answer << "\n";
    return 0;
}