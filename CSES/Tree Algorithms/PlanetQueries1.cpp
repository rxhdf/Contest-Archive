//Tipo de dato muy estricto
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q;

class BinaryLifting{
    const ll LOG = 30; 
    vector<vector<int>> up;
    public:
        BinaryLifting(vector<int> &parent){
            up = vector<vector<int>>(n + 1, vector<int>(LOG));
            for(ll i = 1; i <= n; ++i){
                up[i][0] = parent[i];
            }
            for(ll i = 1; i < LOG; ++i){
                for(ll v = 1; v <= n; ++v){
                    up[v][i] = up[up[v][i - 1]][i - 1];
                }
            }
        }   
        int jump(int node, ll distance){
            int aux = node;
            for(int i = 0; i < LOG; ++i){
                if(distance & (1 << i)){
                    aux = up[aux][i];
                }
            }
            return aux;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;    
    vector<int> parents(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> parents[i];
    }
    BinaryLifting bl(parents);
    while(q--){
        ll a, b;
        cin >> a >> b;
        cout << bl.jump(a, b) << "\n";
    }
    return 0;
}