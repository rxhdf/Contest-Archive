//nodio
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int n, m;
int st[4*MAXN], lazy[4*MAXN];

void build(int start, int end, int node){
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if(start == end){
        st[node] = 0;
		return;
    }
    build(start, mid, left);
    build(mid+1, end, right);
    st[node] = st[left] + st[right];
}

void update(int start, int end, int node, int l, int r){
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if(lazy[node] != 0){
        ++st[node]%=2;
        if(start != end){   
            ++lazy[left]%=2;
            ++lazy[right]%=2;
        }
        lazy[node] = 0;
    }
    if(start > end || start > r || end < l)return;
    if(start >= l && end <= r){
        ++st[node]%=2;
        if(start != end){
            ++lazy[left]%=2;
            ++lazy[right]%=2;
        }
        return;
    }
    update(start, mid, left, l, r);
    update(mid+1, end, right, l, r);
    st[node] = st[left] + st[right];
}
int query(int start, int end, int node, int l, int r){
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if(start > end || start > r || end < l)return 0;
    if(start >= l && end <= r)return st[node];
    return query(start, mid, left, l, r) + query(mid+1, end, right, l, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int k, a, b;
        cin >> k >> a >> b;
        if(k){
            cout << query(1, n, 1, a, b) << "\n";
        }else{
            update(1, n, 1, a, b);
        }
    }

    return 0;
}