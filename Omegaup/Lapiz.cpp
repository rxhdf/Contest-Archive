#include <bits/stdc++.h>

#define MAXN 10001

using namespace std;

struct nodo{
    int x, w;
    friend bool operator<(nodo a, nodo b) {
    return a.w < b.w;
  }
};

int t, x, e, c, l, p;
vector<vector<nodo>> adj(MAXN);
vector<int> dtdp;

vector<int> dijkstra(int origen){
    vector<int> distancia(c, INT32_MAX);
    distancia[origen] = 0;
    priority_queue<nodo> pq;
    pq.push({origen, 0});
    while(!pq.empty()){
        int u = pq.top().x;
        pq.pop();
        for(auto e: adj[u]){
            int v = e.x;
            int we = e.w;
            if(distancia[u] + we < distancia[v]){
                distancia[v] = distancia[u] + we;
                pq.push({v, distancia[v]});
            }
        }
    }
    return distancia;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> x >> e >> c >> l;
    for(int i = 0; i < c; ++i){
        int e1, e2, d;
        cin >> e1 >> e2 >> d;
        adj[e1].push_back({e2, d});
        adj[e2].push_back({e1, d});
    }
    cin >> p;
    auto ds = dijkstra(l);
    for(int i = 0; i < p; ++i){
        int h;
        cin >> h;  
        int aux = ds[h];
        int k = (x * 60) * t;
        if(ds[h] <= k){
            cout << "Si pueden llegar, les tomaria " << aux / (x*60) << " minutos ir a la pizzeria " << h << "\n";
            return 0;
        }
    }
    cout << "No pueden llegar, moriran de hambre\n";
    return 0;
}