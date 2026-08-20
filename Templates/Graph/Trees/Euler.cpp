#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<int> tin, tout, tour, depths, first;
vector<vector<int>> tree;

class SegmentTree{
public:
    vector<pair<int,int>> treeS; // {profundidad, nodo}
    SegmentTree(int n){
        treeS.resize(4 * n + 1, {INT_MAX, -1});
    }
    void build(int tl, int tr, int index, vector<pair<int,int>> &arr){
        if(tl == tr){
            treeS[index] = arr[tl];
        }else{
            int tm = (tl + tr) / 2;
            build(tl, tm, index*2, arr);
            build(tm+1, tr, index*2+1, arr);
            treeS[index] = min(treeS[index*2], treeS[index*2+1]);
        }
    }
    void update(int tl, int tr, int pos, pair<int,int> val, int index){
        if(tl == tr){
            treeS[index] = val;
        }else{
            int tm = (tl + tr)/2;
            if(pos <= tm) update(tl, tm, pos, val, index*2);
            else update(tm+1, tr, pos, val, index*2+1);
            treeS[index] = min(treeS[index*2], treeS[index*2+1]);
        }
    }
    pair<int,int> query(int tl, int tr, int l, int r, int index){
        if(l > r) return {INT_MAX, -1};
        if(tl == l && tr == r) return treeS[index];
        int tm = (tl + tr)/2;
        return min(
            query(tl, tm, l, min(r, tm), index*2),
            query(tm+1, tr, max(l, tm+1), r, index*2+1)
        );
    }
};

int timer = 0;

void euler(int node, int parent, int depth){
    depths[node] = depth;
    if(first[node] == -1) first[node] = timer;
    tin[node] = timer++;
    tour.push_back(node);
    for(auto e: tree[node]){
        if(e != parent) euler(e, node, depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    tree.assign(n, {});
    tin.assign(n, 0);
    depths.assign(n, 0);
    first.assign(n, -1);
    tour.clear();

    for(int i=0;i<n-1;++i){
        int a,b; cin >> a >> b;
        --a; --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    euler(0,0,0);

    vector<pair<int,int>> depthNode(tour.size());
    for(int i=0;i<tour.size();++i) depthNode[i] = {depths[tour[i]], tour[i]};

    SegmentTree ST(depthNode.size());
    ST.build(0, depthNode.size()-1, 1, depthNode);

    while(q--){
        int a,b;
        cin >> a >> b;
        --a; --b;
        int l = first[a], r = first[b];
        if(l>r) swap(l,r);
        int lca_node = ST.query(0, depthNode.size()-1, l, r, 1).second;
        int ans = depths[a] + depths[b] - 2*depths[lca_node];
        cout << ans << "\n";
    }

    return 0;
}
