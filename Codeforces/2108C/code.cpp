#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct DSU {
    vector<int> parent;
    int components;

    DSU(int n) {
        parent.assign(n + 2, -1);
        components = 0;
    }

    int find(int i) {
        if (parent[i] < 0) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
        }
    }

    void activate() {
        components++;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    map<int, vector<int>, greater<int>> groups;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        groups[a[i]].push_back(i);
    }

    DSU dsu(n);
    vector<bool> active(n + 2, false);
    int max_clones = 0;

    for (auto const& [weight, positions] : groups) {
        for (int p : positions) {
            dsu.activate();
            active[p] = true;

            if (p > 1 && active[p - 1]) {
                dsu.unite(p, p - 1);
            }
            if (p < n && active[p + 1]) {
                dsu.unite(p, p + 1);
            }
        }
        max_clones = max(max_clones, dsu.components);
    }

    cout << max_clones << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}