#include <bits/stdc++.h>
using namespace std;


long long binaryExpo(long long  x, long long n, int MOD){
	long long ans = 1;
	x %= MOD;
	while(n > 0){
		if(n & 1){
			ans = (ans * x) % MOD;
		}
		x = (x * x) % MOD;
		n /= 2;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while(tt--){
		long long a, b, c;
		cin >> a >> b >> c;
		long long exp = binaryExpo(b, c, 1e9 + 6); 
		cout << binaryExpo(a, exp, 1e9 + 7) << "\n";
	}

	return 0;
}