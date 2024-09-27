#include <bits/stdc++.h>

using namespace std;

void solve(){
	int N, K, Z = 0, P = 0;
    cin >> N >> K;
    for(int i = 1;  i <= N; ++i){
        int a;
        cin >> a;
        if(a >= K)P += a;
        if(a == 0){
            if(P > 0){
                --P;
                ++Z;
            }
        }
    }
    cout << Z << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while(tt--)
		solve();
	return 0;
}