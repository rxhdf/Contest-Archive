//Ojala encuentren el error
#include <bits/stdc++.h>
#include <utility>

#define MAXN 100003
#define LOG 19
#define ancestro first
#define distancia second
#define ll long long int

using namespace std;

struct node{
  int dist_acumulada;
  int padre;
  int B_shon;
};

int N, Q;
vector<vector<pair<int, int>>> adj(MAXN);
int deptht[MAXN], DMH[MAXN], MH[MAXN], fat[MAXN];
vector<pair<int, int>> querys[MAXN];
pair<int, int> distpadre[LOG][MAXN];
pair<int, int> ancestros[LOG][MAXN];
int hijos[2][MAXN];
node MS[MAXN];
int ST[LOG][MAXN];
int res[MAXN];

void init(int nodo, int padre, int depth, int dis_padre){
  deptht[nodo] = depth;
  distpadre[0][nodo] = make_pair(dis_padre, padre);
  fat[nodo] = padre;
  for(int i = 1; i <= LOG; ++i){
    distpadre[i][nodo].ancestro = distpadre[i-1][distpadre[i-1][nodo].ancestro].ancestro; 
    distpadre[i][nodo].distancia = distpadre[i-1][nodo].distancia + distpadre[i-1][distpadre[i-1][nodo].ancestro].distancia;
  }
  for(auto e: adj[nodo]){
    if(e.first == padre)continue;
    init(e.first, nodo, depth + 1, e.distancia);
    if(hijos[0][e.first] + e.distancia > hijos[0][nodo]){
      MH[nodo] = e.first;
      DMH[nodo] = e.distancia;
      hijos[1][nodo] = hijos[0][nodo];
      hijos[0][nodo] = hijos[0][e.first] + e.distancia;
    }else if (hijos[0][e.first] + e.distancia > hijos[1][nodo]){
      hijos[1][nodo] = hijos[0][e.first] + e.distancia;
    }
  }
}

void actualiza_stack(int nodo, int distanciahijo, int distanciapadre){
  int pos = fat[nodo];
  int disac = distanciapadre;
  while(pos && distanciahijo >= disac + MS[pos].B_shon){
    disac += MS[pos].dist_acumulada;
    pos = MS[pos].padre;
  }
  MS[nodo].B_shon = distanciahijo;
  MS[nodo].dist_acumulada = disac;
  MS[nodo].padre = pos;
  ST[0][nodo] = pos;
  for(int i = 1; i <= LOG; ++i){
    ST[i][nodo] = ST[i-1][ST[i-1][nodo]];
  }
}

int get_dis(int l, int r){
  int a = deptht[l];
  int b = deptht[r];
  int dif = a - b;
  int sum = 0;
  for(int i = 0; i <= LOG; ++i){
    if(dif & (1<<i)){
      sum += distpadre[i][l].distancia;
      l = distpadre[i][l].first;
    }
  }
  return sum;
}

void solve(int nodo, int padre, int dispadre){
  for(auto q: querys[nodo]){
    int d = deptht[q.first];
    int pos = padre;
    for(int i = 1; i <= LOG; ++i){
      if(deptht[ST[i][pos]] >= d)pos = ST[i][pos];
    }
    int dAncestro = 0;
    if(deptht[pos] >= d){
      dAncestro = get_dis(nodo, pos) + MS[pos].B_shon;
    }
    int x = dAncestro, y = hijos[0][nodo], z = hijos[1][nodo];
    if(x < y)swap(x, y);
    if(y < z)swap(y, z);
    res[q.first] = x + y;
  }
  if(MH[nodo] > 0){
     actualiza_stack(nodo, hijos[1][nodo], dispadre);
     solve(MH[nodo], nodo, DMH[nodo]);
  }
  if(adj[nodo].size() > 2 || (adj[nodo].size() == 2 && nodo == 1)){
    for(auto u: adj[nodo]){
      if(u.first == padre || u.first == MH[nodo])continue;
      solve(u.first, nodo, u.distancia);
    }
  } 
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  for(int i = 1; i < N; ++i){
    int a, b, d;
    cin >> a >> b >> d;
    adj[a].push_back(make_pair(b, d));
    adj[b].push_back(make_pair(a, d));
  }
  for(int i = 1; i <= Q; ++i){
    int a, b;
    cin >> a >> b;
    querys[a].push_back({i, b});
  }
  init(1, 0, 1, 0);
  solve(1, 0, 0);
  for(int i = 1; i <= Q; ++i)cout << res[i] << "\n";
  
  return 0;
}
