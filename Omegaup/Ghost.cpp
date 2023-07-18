//20 points (PA)
#include <bits/stdc++.h>

#define MAXN 10002
#define nodo pair<int, int>
#define X first
#define W second
#define INF INT32_MAX

using namespace std;

int N, M, F, Fotos = 0;
vector<vector<nodo>> adj(MAXN);

vector<int> dijkstra(int src){
    priority_queue<nodo> pq;
    vector<int> distancia(MAXN, INF);
    pq.push(make_pair(src, 0));
    distancia[src] = 0;
    while(!pq.empty()){
        int u = pq.top().X;
        pq.pop();
        for(auto e: adj[u]){
            int v = e.X;
            int we = e.W;
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
    cin >> N >> M;
    for(int i = 0; i < M; ++i){ 
        int a, b;
        cin >> a >> b;
        adj[a].push_back(make_pair(b, 1));
        adj[b].push_back(make_pair(a, 1));
    }
    auto dist = dijkstra(0);
    cin >> F;
    for(int i = 0; i < F; ++i){
        int a;
        cin >> a;
        if(dist[a] <= i){
            Fotos++;
            dist = dijkstra(a);
        }
    }
    cout << Fotos << "\n";
    

    return 0;
}
