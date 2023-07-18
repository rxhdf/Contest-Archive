#include <bits/stdc++.h>

using namespace std;

int n;
int BIT[1025][1025];
void update(int x, int y, int val){
	for(int i = x; i < n; i = i | (i+1)){
		for(int j = y; j < n; j = j | (j+1)){
			BIT[i][j] += val;
		}
	}
}
int query(int x, int y){
	int sum = 0;
	for(int i = x; i >= 0; i = (i & (i + 1)) - 1){
		for(int j = y; j >= 0; j = (j & (j + 1)) - 1){
			sum += BIT[i][j];
		}
	}
	return sum;
}	

int main(){	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin >> c >> n;		
	while(c != 3){
		cin >> c;
		if(c == 1){
			int a, b, c;
			cin >> a >> b >> c;
			update(a, b, c);
		}
		else if (c == 2){
			int l, b, r, t;
			cin >> l >> b >> r >> t;
			cout << query(r, t) - query(l-1, t) - query(r, b-1) + query(l-1, b-1) << "\n";
		}
		
	}
	return 0;
}