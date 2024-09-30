#include <bits/stdc++.h>
#include <utility>
#define MAX (int) 1e5 + 5

using namespace std;

int N, Q;
vector<vector<pair<int, int>>> Tree;
bool visited[MAX];
int parents[MAX], depth[MAX];

void dfs_parents(int node, int parent){
    depth[node] = depth[parent] + 1;
    parents[node] = parent;
    for(auto e: Tree[node]){
        if(parent != e.first){
            dfs_parents(e.first, node);
        }
    }
}
int dfs_bruta(int node){

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    Tree.resize(N + 1);
    for(int i = 1; i < N; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        Tree[a].push_back(make_pair(b, c));
        Tree[b].push_back(make_pair(a, c));
    }
    memset(visited, 0, sizeof(visited));
    memset(depth, 0, sizeof(depth));
    dfs_parents(1, 1);
    for(int i = 1; i <= N; ++i){
        cout << parents[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= N; ++i){
        cout << depth[i] << " ";
    }
    for(int i = 1; i <= N; ++i){
        memset(visited, 0, sizeof(visited));
        dfs_bruta(i);
    }
    
    return 0;
}