#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class DisjointSet{
    private:
        vector<int> parents;
        vector<int> sizes;

    public:
        DisjointSet(int size): sizes(size + 2, 1), parents(size + 2){
            for(int i = 0; i < size; ++i){
                parents[i] = i;
            }
        }
        int find_set(int node){
            return parents[node] == node? node: (parents[node] = find_set(parents[node])); 
        }

        void merge_set(int u, int v){
            int x_root = find_set(u);
            int y_root = find_set(v);
            if(x_root == y_root)return;
            
            if(sizes[x_root] < sizes[y_root]){
                swap(x_root, y_root);
            }
            sizes[x_root] += sizes[y_root];
            parents[y_root] = x_root;
        }
        int sz(int node){
            return sizes[find_set(node)];
        }
};

struct Edge{
    int u, v, weight;
    friend bool operator<(const Edge& A, const Edge& B){
        return A.weight < B.weight;
    };
};

int n, m;
vector<Edge> aristas;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        aristas.push_back({u, v, w});
    }
    sort(aristas.begin(), aristas.end());
    DisjointSet dsu(n);
    ll ans = 0;
    for(auto [u, v, w]: aristas){
        if(dsu.find_set(u) != dsu.find_set(v)){
            ans += w;
            dsu.merge_set(u, v);
        }
    }
    if(dsu.sz(1) == n)cout << ans << "\n";
    else cout << "IMPOSSIBLE\n";
    return 0;
}