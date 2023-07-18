#include <bits/stdc++.h>

#define MAXN 100001

int a[MAXN], st[4*MAXN], dif[MAXN-1];

using namespace std;

void build(int start, int end, int node){
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if(start == end){
        st[node] = dif[start];
		return;
    }
    build(start, mid, left);
    build(mid+1, end, right);
    st[node] = st[left] + st[right];
}
void update(int start, int end, int node, int index, int val){
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if(start == end){
        st[node] += val;
        return;
    }else {
        if(start <= index && index <= mid){
            update(start, mid, left, index, val);
        }else {
            update(mid+1, end, right, index, val);
        }
    }
    st[node] = st[left] + st[right];
}
int query(int start, int end, int node, int l, int r){
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if(start > r || end < l)return 0;
    if(start >= l && end <= r){
        return st[node];
    }
    int c1 = query(start, mid, left, l, r);
    int c2 = query(mid+1, end, right, l, r);
    return (c1 + c2);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, u, q;
    cin >> n >> u >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(i > 1)dif[i-1] = abs(a[i] - a[i-1]);
    }
    build(1, n-1, 1);
    map<int, pair<int,int>> up;
    for(int i = 0; i < u; ++i){
        int x, h, m;
        cin >> x >> h >> m;
        up[m] = make_pair(x, h);
    }
    auto it = up.begin();
    for(int i = 0; i < q; ++i){
        int r1, r2, t;
        cin >> r1 >> r2 >> t;
        for(int x = 1; x < 2*n+1; ++x){
            cout << st[x] << " ";
        }
        while(it != up.end() && it->first <= t){
            int index = it->second.first;
            int inc = it->second.second;
            a[index] += inc;
            update(1,n-1,1,index,abs(a[index] - a[index-1]));
            it++;
        }
        cout << query(1, n-1, 1, r1, r2-1) << "\n";
    }

    return 0;
}