#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

stack<pair<int, int>> pila;

int solve(int x){
	int t = 0;
	while(!pila.empty() && pila.top().first < x){
		t = max(t + 1, pila.top().second);
		pila.pop();
	}
	pila.push(make_pair(x, t));
	return t;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = n - 1; i >= 0; --i){
		ans = max(ans, solve(a[i]));
	}
	cout << ans << "\n";
	return 0;
}