#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 1e9 + 3;

class DisjointSet{
    private:
        vector<int> parents;
        vector<int> sizes;

    public:
        DisjointSet(int size): sizes(size, 1), parents(size){
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    DisjointSet dsu(n + 1);
    vector<int> p(n + 1), conjunto(n + 1), state(n + 1, 3);
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        mp[p[i]] = i;
    }
    for(int i = 1; i <= n; ++i){
        if(mp.count(a - p[i])){
            dsu.merge_set(i, mp[a - p[i]]);
            conjunto[i] |= 1;
        }   
        if(mp.count(b - p[i])){
            dsu.merge_set(i, mp[b - p[i]]);
            conjunto[i] |= 2;
        }    
    }
    for(int i = 1; i <= n; ++i){
        state[dsu.find_set(i)] &= conjunto[i];
    }
    for(int i = 1; i <= n; ++i){
        if(!state[dsu.find_set(i)]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i){
        if(state[dsu.find_set(i)] == 2){
            cout << "1 ";
        }else{
            cout << "0 ";
        }
        
    }
    cout << "\n";
    return 0;
}