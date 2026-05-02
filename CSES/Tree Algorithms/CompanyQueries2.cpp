#include <bits/stdc++.h>
#include <stack>

using namespace std;

class Tree{
    const int LOG = 30;
    vector<vector<int>> adj;
    vector<vector<int>> up; 
    vector<int> depth;
    vector<int> parents;
    
    public:
        Tree(vector<int> parents, vector<vector<int>> adj, int n){
            this->adj = adj;
            up = vector<vector<int>>(n + 1, vector<int>(LOG));
            depth = vector<int>(n + 1);
            this->parents = parents;
            
            //UP
            for(int i = 0; i < n; ++i){
                up[i][0] = parents[i];
            }
            for(int j = 1; j < LOG; ++j){
                for(int v = 0; v < n; ++v){
                    int halfway = up[v][j - 1];
                    if(halfway == -1){
                        up[v][j] = -1;
                    }else{
                        up[v][j] = up[halfway][j - 1];
                    }
                    
                }
            }
            //depths
            auto get_depths = [&](){
                stack<int> st;
                vector<bool> visited(n, false);
                st.push(0);
                visited[0] = true;
                depth[0] = 0;
                while(!st.empty()){
                    int actual = st.top();
                    st.pop();
                    for(auto v: adj[actual]){
                        if(!visited[v]){
                            depth[v] = depth[actual] + 1;
                            visited[v] = true;
                            st.push(v);
                        }
                    }
                }
            };
            get_depths();
        }

        int kesimo(int node, int kancestor){
            if(kancestor > parents.size())return -1;
            int aux = node;
            for(int i = 0; i < LOG; ++i){
                if(kancestor & (1 << i)){
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
            //lift to same level
            node_a = kesimo(node_a, depth[node_a] - depth[node_b]);
            if(node_a == node_b){
                return node_a;
            }

            for(int i = LOG; i >= 0; --i){
                if(up[node_a][i] != up[node_b][i]){
                    node_a = up[node_a][i];
                    node_b = up[node_b][i];
                }
            }
            return up[node_a][0];
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> parents(n);
    vector<vector<int>> graph(n);
    for(int i = 1; i < n; ++i){
        cin >> parents[i];
        parents[i]--;
        graph[parents[i]].push_back(i);
        graph[i].push_back(parents[i]);
    }
    Tree tree(parents, graph, n);
    for(int i = 0; i < q; ++i){
        int u, v;
        cin >> u >> v;
        cout << tree.lca(--u, --v)  +  1 << "\n";
    }
    return 0;
}