#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MAXN 100003

class sg {
	public:
	int size;
	int tree[2*MAXN];
	
	void build(int x){
		for(int i = 0; i <= x; ++i){
			tree[i] = 0;
		}
		size = x;
	}
	void update(int idx, int val){
		while(idx <= size){
			tree[idx] += val;
			idx += (idx&-idx);
		}
	}
	ll query(int idx){
		int sum = 0;
		while(idx > 0){
			sum += tree[idx];
			idx-=(idx&-idx);
		}
		return sum;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll c;
	ll n, k;
	ll presum = 0;
	ll ans = 0;
	sg Trfee;
	Trfee.build(2 * MAXN);
	cin >> n >> k;
	Trfee.update(n, 1);
	for(int i = 0; i < n; ++i){
		cin >> c;
		c >= k ? presum++ : presum--;
		ans += Trfee.query(presum + n);
		Trfee.update(presum + n, 1);
	}
	
	cout <<  ans << "\n";
	return 0;
}