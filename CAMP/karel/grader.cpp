// Atrapando a Karel — grader local por funciones (un caso).
// El oponente juega de forma completamente aleatoria; no es adaptativo.
// El juez oficial si es adaptativo y juega de manera mucho mas fuerte.
#include "karel.h"
#include <bits/stdc++.h>
using namespace std;

namespace {
  const int COMI_DF[5] = {0, 0, -1, 0, 1};  // 1:E 2:N 3:O 4:S
  const int COMI_DC[5] = {0, 1, 0, -1, 0};

  int COMI_N;
  set<array<int, 4>> COMI_muros;

  int COMI_kf = -1, COMI_kc = -1;
  string COMI_lado;
  bool COMI_lado_elegido = false;
  int COMI_ronda = 0;
  mt19937 COMI_rng;

  [[noreturn]] void COMI_quit(double outcome, const string &msg) {
    if (outcome >= 1.0) cout << "Correcto";
    else cout << "Incorrecto";
    if (!msg.empty()) cout << ": " << msg;
    cout << "\n";
    exit(0);
  }

  array<int, 4> COMI_arista(int f, int c, int d) {
    int nf = f + COMI_DF[d], nc = c + COMI_DC[d];
    array<int, 4> a = {f, c, nf, nc};
    array<int, 4> b = {nf, nc, f, c};
    return (a < b) ? a : b;
  }

  bool COMI_enTablero(int f, int c) { return f >= 1 && f <= COMI_N && c >= 1 && c <= COMI_N; }
  bool COMI_hayMuro(int f, int c, int d) { return COMI_muros.count(COMI_arista(f, c, d)) > 0; }

  bool COMI_atrapado(int f, int c) {
    for (int d = 1; d <= 4; d++)
      if (!COMI_hayMuro(f, c, d)) return false;
    return true;
  }

  // Aristas libres (representacion canonica), excluyendo duplicados.
  vector<array<int, 3>> COMI_murosLibres() {
    set<array<int, 4>> vistos;
    vector<array<int, 3>> v;
    for (int f = 1; f <= COMI_N; f++)
      for (int c = 1; c <= COMI_N; c++)
        for (int d = 1; d <= 4; d++) {
          int nf = f + COMI_DF[d], nc = c + COMI_DC[d];
          if (nf < 1 || nf > COMI_N || nc < 1 || nc > COMI_N) continue;
          array<int, 4> e = COMI_arista(f, c, d);
          if (COMI_muros.count(e)) continue;
          if (!vistos.insert(e).second) continue;
          v.push_back({f, c, d});
        }
    return v;
  }

  // Todas las direcciones abiertas desde la casilla actual de Karel.
  vector<int> COMI_movimientosLibres() {
    vector<int> v;
    for (int d = 1; d <= 4; d++)
      if (!COMI_hayMuro(COMI_kf, COMI_kc, d)) v.push_back(d);
    return v;
  }
}

void recibir_muro(int &f, int &c, int &d) {
  if (COMI_lado_elegido && COMI_lado != "karel") COMI_quit(0.0, "llamaste recibir_muro pero no elegiste Karel");
  if (!COMI_lado_elegido) { COMI_lado = "karel"; COMI_lado_elegido = true; }
  if (++COMI_ronda > 66) COMI_quit(0.0, "Karel no escapo en 66 pasos");

  auto libres = COMI_murosLibres();
  if (libres.empty()) COMI_quit(0.0, "no hay muros disponibles");
  uniform_int_distribution<int> dis(0, (int)libres.size() - 1);
  auto m = libres[dis(COMI_rng)];
  COMI_muros.insert(COMI_arista(m[0], m[1], m[2]));
  f = m[0]; c = m[1]; d = m[2];
}

void mover(int d) {
  if (!COMI_lado_elegido || COMI_lado != "karel") COMI_quit(0.0, "mover sin elegir Karel");
  if (d < 1 || d > 4) COMI_quit(0.0, "Karel dio una direccion invalida: " + to_string(d));
  if (COMI_hayMuro(COMI_kf, COMI_kc, d)) COMI_quit(0.0, "Karel intento cruzar un muro (direccion " + to_string(d) + ")");
  int nf = COMI_kf + COMI_DF[d], nc = COMI_kc + COMI_DC[d];
  if (!COMI_enTablero(nf, nc)) COMI_quit(1.0, "Karel escapo en " + to_string(COMI_ronda) + " pasos");
  COMI_kf = nf; COMI_kc = nc;
}

void poner_muro(int f, int c, int d) {
  if (COMI_lado_elegido && COMI_lado != "diablo") COMI_quit(0.0, "llamaste poner_muro pero no elegiste diablo");
  if (!COMI_lado_elegido) { COMI_lado = "diablo"; COMI_lado_elegido = true; }
  if (++COMI_ronda > 66) COMI_quit(0.0, "el diablo no atrapo a Karel en 66 muros");
  if (f < 1 || f > COMI_N || c < 1 || c > COMI_N || d < 1 || d > 4)
    COMI_quit(0.0, "muro invalido del diablo: " + to_string(f) + " " + to_string(c) + " " + to_string(d));
  COMI_muros.insert(COMI_arista(f, c, d));
}

int recibir_movimiento() {
  if (!COMI_lado_elegido || COMI_lado != "diablo") COMI_quit(0.0, "recibir_movimiento sin elegir diablo");
  if (COMI_atrapado(COMI_kf, COMI_kc)) COMI_quit(1.0, "Karel atrapado en " + to_string(COMI_ronda) + " muros");

  auto libres = COMI_movimientosLibres();
  if (libres.empty()) COMI_quit(1.0, "Karel atrapado en " + to_string(COMI_ronda) + " muros");

  // Mezclar para no favorecer un orden de direcciones.
  shuffle(libres.begin(), libres.end(), COMI_rng);
  for (int d : libres) {
    int nf = COMI_kf + COMI_DF[d], nc = COMI_kc + COMI_DC[d];
    if (!COMI_enTablero(nf, nc)) {
      // Karel escapa: el concursante (diablo) pierde.
      COMI_quit(0.0, "Karel escapo: el diablo dejo una salida abierta");
    }
    COMI_kf = nf; COMI_kc = nc;
    return d;
  }
  COMI_quit(1.0, "Karel atrapado en " + to_string(COMI_ronda) + " muros");
  return 0;
}

int main() {
  int n, s;
  if (!(cin >> n)) return 0;
  s = 0;
  if (!(cin >> s)) cin.clear();
  if (n < 1 || n > 64) { cout << "Incorrecto\n"; return 0; }
  COMI_rng.seed(s);
  COMI_N = n;
  COMI_kf = COMI_kc = (COMI_N + 1) / 2;
  jugar(n);
  COMI_quit(0.0, "nadie gano en menos de 67 movimientos");
}
