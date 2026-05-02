#include <bits/stdc++.h>

using namespace std;

int n, q;

class Tree{
    const int LOG = 30;
    vector<vector<int>> up, adj;
    vector<int> depth;
    
    public:
        Tree(int n, vector<vector<int>> &adj){
            this->adj = adj;
            up.assign(n + 2, vector<int>(LOG + 1, -1));
            depth.assign(n + 2, 0);
            auto get_depths = [&](int start){
                stack<int> st;
                vector<bool> visited(n + 1, false);
                depth[start] = 0;
                visited[start] = true;
                st.push(start);
                up[0][0] = -1;
                while(!st.empty()){
                    int actual = st.top();
                    st.pop();
                    for(int v: adj[actual]){
                        if(!visited[v]){
                            st.push(v);
                            visited[v] = true;
                            depth[v] = depth[actual] + 1;
                            up[v][0] = actual;
                        }
                    }
                }
            };
            get_depths(0);
            

            for(int i = 1; i < LOG; ++i){
                for(int v = 0; v < n; ++v){
                    if(up[v][i - 1] != -1){
                        up[v][i] = up[up[v][i - 1]][i - 1];
                    }
                }
            }
        }

        int kancestor(int node, int k){
            int aux = node;
            for(int i = 0; i < LOG; ++i){
                if(k & (1 << i)){
                    aux = up[aux][i];
                    if(aux == -1)break;
                }
            }
            return aux;
        }

        int lca(int node_a, int node_b){
            if(depth[node_a] < depth[node_b])swap(node_a, node_b);
            node_a = kancestor(node_a, depth[node_a] - depth[node_b]);
            
            if(node_a == node_b){
                return node_a;
            } 

            for(int i = LOG - 1; i >= 0; --i){
                if(up[node_a][i] != up[node_b][i]){
                    node_a = up[node_a][i];
                    node_b = up[node_b][i];
                }
            }
            return up[node_a][0];
        }

        int distance(int node_a, int node_b){
            int LCA = lca(node_a, node_b);

            int distans = depth[node_a] + depth[node_b] - (2 * depth[LCA]);
            return distans;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Tree arbol(n, adj);
    while(q--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << arbol.distance(a,b) << "\n";
    }
    return 0;
}