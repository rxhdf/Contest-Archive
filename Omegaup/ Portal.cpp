#include <bits/stdc++.h>
#define ARRIBA 0
#define ABAJO 1
#define DERECHA 2
#define IZQUIERDA 3
#define TIME second
#define Cors first
#define X first
#define Y second
#define Nodo pair<pair<int, int>, int>

using namespace std;

const int MAXN = 1300;

Nodo In, Fin;

int N, M, steps = INT32_MIN;
vector<vector<char>> MP(MAXN, vector<char>(MAXN, '.'));
vector<vector<vector<int>>> DM(6,
                               vector<vector<int>>(MAXN, vector<int>(MAXN, 0)));
vector<vector<int>> PX(MAXN, vector<int>(MAXN, 0));
vector<int> f = {-1, 0, 1, 0};
vector<int> c = {0, 1, 0, -1};
priority_queue<Nodo> pq;

int bfs() {
  bool encontrado = false;
  int PMin = INT32_MAX;
  pq.push(In);
  while (!pq.empty()) {
    Nodo Ac = pq.top();
    pq.pop();
    int time = Ac.TIME;
    auto pos = Ac.Cors;

    // BFS
    for (int i = 0; i < 4; ++i) {
      int NX = pos.X + f[i];
      int NY = pos.Y + c[i];
      time++;
      if (MP[NX][NY] == '#' || NX <= 0 || NX > N || NY <= 0 || NY > M)
        continue;
      if (MP[NX][NY] == 'X') {
        encontrado = true;
        PMin = min(time, PMin);
      }
      pq.push(make_pair(make_pair(NX, NY), time));
    }
    // Portal de Arriba
    int distanciaPortal = DM[ARRIBA][pos.X][pos.Y] - 1;
    Nodo PA =
        make_pair(make_pair(pos.X - distanciaPortal, pos.Y), distanciaPortal);

    // Portal de la Derecha
    distanciaPortal = DM[DERECHA][pos.X][pos.Y] - 1;
    Nodo PD =
        make_pair(make_pair(pos.X, pos.Y + distanciaPortal), distanciaPortal);

    // Portal de Izquierda
    distanciaPortal = DM[IZQUIERDA][pos.X][pos.Y] - 1;
    Nodo PI =
        make_pair(make_pair(pos.X, pos.Y - distanciaPortal), distanciaPortal);

    // Portal de Abajo
    distanciaPortal = DM[ABAJO][pos.X][pos.Y] - 1;
    Nodo PC =
        make_pair(make_pair(pos.X + distanciaPortal, pos.Y), distanciaPortal);

    // Moverse al portal de ARRIBA
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++i) {
      cin >> MP[i][j];
      if (MP[i][j] != '#') {
        DM[ARRIBA][i][j] = DM[ARRIBA][i - 1][j] + 1;
        DM[IZQUIERDA][i][j] = DM[IZQUIERDA][i][j - 1] + 1;
      }
      if (MP[i][j] == 'O')
        In = make_pair(make_pair(i, j), 0);
      else if (MP[i][j] == 'X')
        Fin = make_pair(make_pair(i, j), 0);
    }
  }
  for (int i = N; i >= 1; --i) {
    for (int j = M; j >= 1; --j) {
      if (MP[i][j] != '#') {
        DM[ABAJO][i][j] = DM[ABAJO][i][j + 1] + 1;
        DM[DERECHA][i][j] = DM[DERECHA][i + 1][j] + 1;
      }
    }
  }
  bfs();
  return 0;
}
