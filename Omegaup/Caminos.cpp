#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int h, w;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w;
	vector<vector<ll> > m(h + 1, vector<ll>(w + 1, 1));
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			m[i][j] = m[i-1][j] + m[i][j-1];
		}
	}
	cout << m[h][w] << "\n";
	return 0;
}