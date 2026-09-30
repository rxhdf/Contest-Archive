#include <bits/stdc++.h>
#define ll long long
#define INF (ll)1e18
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, s, b;
    cin >> n >> m >> k;
    cin >> s;
    int initialpowers = 0;
    for(int i = 0; i < s; ++i){
        int x;
        cin >> x;
        initialpowers |= (1 << x);
    }
    vector<int> needed(n + 1, 0), reward(n + 1, 0);
    for(int i = 2; i <= n; ++i){
        int mask_ned = 0, mask_rew = 0, r, g;
        cin >> r;
        for(int j = 0; j < r; ++j){
            int x;
            cin >> x;
            mask_ned |= (1 << x);
        }
        needed[i] = mask_ned;
        cin >> g;
        for(int j = 0; j < g; ++j){
            int x;
            cin >> x;
            mask_rew |= (1 << x);
        }
        reward[i] = mask_rew;
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; ++i){
        int u, v, e;
        cin >> u >> v >> e;
        adj[u].push_back({v, e});
    }
    cin >> b;
    if(b == 1){
        cout << 0 << endl;
        return 0;
    }
    //costo, nodo, mascara de poderes
    vector<vector<ll>> dist(n + 1, vector<ll>((1 << k), INF));
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    dist[1][initialpowers] = 0;
    pq.push({0, 1, initialpowers});

    //dijsktra feo
   while(!pq.empty()){
        auto [cost, node, mask] = pq.top();
        pq.pop();
        if(cost != dist[node][mask])continue;   
        if(node == b)continue;
        for(auto [nxt_node, edge_cost]: adj[node]){
            if((needed[nxt_node] & mask) == needed[nxt_node]){
                ll nxt_mask = (mask & ~needed[nxt_node]) | reward[nxt_node];
                ll new_cost = cost + edge_cost; 
                if(new_cost < dist[nxt_node][nxt_mask]){
                    dist[nxt_node][nxt_mask] = new_cost;
                    pq.push({new_cost, nxt_node, nxt_mask});
                }
            }
        }
    }   
    ll ans = *min_element(dist[b].begin(), dist[b].end());
    if(ans != INF){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    } 
    return 0;   
}