#include <bits/stdc++.h>

#define MAXN 2000100
using namespace std;

int N, M;
vector<vector<pair<int, int>>> tree(MAXN);

int XOR[MAXN];

void solve(int nodo, int padre){
  for(auto e: tree[nodo]){
    if(e.first == padre)continue;
    XOR[e.first] =  XOR[nodo] ^ e.second;
    solve(e.first, nodo);
  }
}


int main(){
  ios_base::sync_with_stdio();
  cin.tie(0);
  cin >> N >> M;
  for(int i = 1; i < N; ++i){
    int a, b, c;    
    cin >> a >> b >> c;
    tree[a].push_back({b, c});
    tree[b].push_back({a, c});
  }
  solve(1, 0);
  for(int i = 0; i < M; ++i){
    int a, b;
    cin >> a >> b;
    int Ans = XOR[a] ^ XOR[b];
    cout << Ans << "\n";
  }
  return 0;
}
