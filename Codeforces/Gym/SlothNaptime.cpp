#include <bits/stdc++.h>

using namespace std;

class Tree{
    vector<int> depth;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    const int LOG = 30;
    
    public:
        Tree(vector<vector<int>> &adj, int n){
            this->adj = adj;
            up.assign(n, vector<int>(LOG, -1));
            depth.assign(n, 0);

            auto build = [&](int start){
                vector<bool> visited(n);
                stack<int> st;

                visited[start] = true;
                st.push(start);

                while(!st.empty()){
                    int actual = st.top();
                    st.pop();

                    for(int v: adj[actual]){
                        if(!visited[v]){
                            up[v][0] = actual;
                            visited[v] = true;
                            depth[v] = depth[actual] + 1;
                            st.push(v);
                        }
                    }
                }
            };
            build(0);
            for(int i = 1; i < LOG; ++i){
                for(int v = 0; v < n; ++v){
                    int halfway = up[v][i - 1];
                    if(halfway == -1){
                        up[v][i] = -1;
                    }else{
                        up[v][i] = up[halfway][i - 1];
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
            if(depth[node_a] < depth[node_b]){
                swap(node_a, node_b);
            }

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

        int get_distance(int node_a, int node_b){
            int l = lca(node_a, node_b);

            return depth[node_a] + depth[node_b] - (2 * depth[l]);
        }

        int query(int node_start, int node_finish, int energy){
            int distance = get_distance(node_start, node_finish);

            if(distance <= energy){
                return node_finish;
            }

            int l = lca(node_start, node_finish);

            int d_from_a_to_l = depth[node_start] - depth[l];
            int d_from_b_to_l = depth[node_finish] - depth[l];

            if(d_from_a_to_l > energy){
                return kancestor(node_start, energy);
            }else{
                energy -= d_from_a_to_l;
                int rest = d_from_b_to_l - energy;
                return kancestor(node_finish, rest);
            }
            return 0;
        }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    vector<vector<int>> adj(n);    
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    Tree arbol(adj, n);
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        cout << arbol.query(a, b, c) + 1 << "\n";
    }

    return 0;
}