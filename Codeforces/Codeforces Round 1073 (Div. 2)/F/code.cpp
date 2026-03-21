#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;

struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Union by size
            if (size[root_i] < size[root_j]) {
                parent[root_i] = root_j;
                size[root_j] += size[root_i];
            } else {
                parent[root_j] = root_i;
                size[root_i] += size[root_j];
            }
        }
    }
    int get_size(int i) {
        return size[find(i)];
    }
};

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long InverseMod(long long n) {
    return power(n, MOD - 2);
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dsu.unite(u, v);
    }

    int root_comp = dsu.find(n);
    int max_init_neighbor = 0;
    for (int neighbor : adj[n]) {
        max_init_neighbor = max(max_init_neighbor, neighbor);
    }

    vector<int> roots;
    vector<int> comp_id(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (dsu.parent[i] == i) {
            comp_id[i] = roots.size();
            roots.push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        comp_id[i] = comp_id[dsu.find(i)];
    }

    int k = roots.size();
    
    if (k == 1) {
        for (int i = 1; i < n; ++i) {
            if (i == max_init_neighbor) cout << "1 ";
            else cout << "0 ";
        }
        cout << "\n";
        return;
    }

    int r_idx = comp_id[root_comp];

    vector<long long> s(k);
    for(int i=0; i<k; ++i) s[i] = dsu.size[roots[i]];

    vector<long long> Val(k);
    vector<int> zero_indices; 
    long long Prod = 1;
    long long SumTerm = 0;

    for (int i = 0; i < k; ++i) {
        if (i == r_idx) continue;
        long long val = ((long long)(n - 1) * s[i]) % MOD;
        Val[i] = val;
        
        if (val == 0) {
            zero_indices.push_back(i);
        } else {
            Prod = (Prod * val) % MOD;
            long long inv = InverseMod(val);
            long long term = (s[i] * s[i]) % MOD;
            term = (term * inv) % MOD;
            SumTerm = (SumTerm + term) % MOD;
        }
    }

    long long prev_F = 0;

    for (int v = 1; v < n; ++v) {
        int c_idx = comp_id[v];
        
        if (c_idx != r_idx) {
            long long old_val = Val[c_idx];
            long long new_val = (old_val + 1) % MOD;
            Val[c_idx] = new_val;

            if (old_val == 0) {
                for(size_t z=0; z<zero_indices.size(); ++z) {
                    if(zero_indices[z] == c_idx) {
                        zero_indices[z] = zero_indices.back();
                        zero_indices.pop_back();
                        break;
                    }
                }
            } else {
                long long inv = InverseMod(old_val);
                Prod = (Prod * inv) % MOD;
                long long term = (s[c_idx] * s[c_idx]) % MOD;
                term = (term * inv) % MOD;
                SumTerm = (SumTerm - term + MOD) % MOD;
            }

            if (new_val == 0) {
                zero_indices.push_back(c_idx);
            } else {
                Prod = (Prod * new_val) % MOD;
                long long inv = InverseMod(new_val);
                long long term = (s[c_idx] * s[c_idx]) % MOD;
                term = (term * inv) % MOD;
                SumTerm = (SumTerm + term) % MOD;
            }
        }
        long long current_F = 0;
        if (v < max_init_neighbor) {
            current_F = 0;
        } else {
            int z_cnt = zero_indices.size();
            if (z_cnt == 0) {
                long long term = (1 - SumTerm + MOD) % MOD;
                current_F = (Prod * term) % MOD;
            } else if (z_cnt == 1) {
                int z_idx = zero_indices[0];
                long long s_z = s[z_idx];
                long long term = (MOD - (s_z * s_z) % MOD) % MOD;
                current_F = (Prod * term) % MOD;
            } else {
                current_F = 0;
            }
        }

        long long ans = (current_F - prev_F + MOD) % MOD;
        cout << ans << (v == n - 1 ? "" : " ");
        prev_F = current_F;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}