#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1001;
const int MOD = 1e9 + 7;
 
int N;
bool ok[MAXN][MAXN];
long long int dp[MAXN][MAXN];
 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			char C;
			cin >> C;
			if(C == '*')ok[i][j] = true;
			else ok[i][j] = false;
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(ok[i][j])dp[i][j] = 0;
			else {
				if(i > 0)dp[i][j] += dp[i-1][j];
				if(j > 0)dp[i][j] += dp[i][j-1];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[N-1][N-1] << "\n";
	return 0;
}
