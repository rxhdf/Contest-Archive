#include "memorama.h"
#include <bits/stdc++.h>
using namespace std;

namespace {
  const int MAX_N = 50;
  int COMI_T, COMI_N, COMI_K;
  int COMI_P[MAX_N];
  int COMI_A[MAX_N * 2];
  int COMI_flip;
  int COMI_ans;
  int COMI_used[MAX_N];

  [[noreturn]] void COMI_quit(int code, const string &msg) {
    if (code == 0) cout << "Correcto";
    else cout << "Incorrecto";
    if (!msg.empty()) cout << ": " << msg;
    cout << "\n";
    exit(0);
  }
}

int Voltea(int I, int J) {
  COMI_flip++;
  if (COMI_flip > COMI_K) {
    COMI_quit(2, "se llamo mas de K veces a Voltea");
  }
  if (I == J || I < 0 || J < 0 || I >= 2 * COMI_N || J >= 2 * COMI_N) {
    COMI_quit(1, "Voltea con indices invalidos");
  }
  if (COMI_P[COMI_A[I]] < COMI_P[COMI_A[J]]) return COMI_A[I];
  else return COMI_A[J];
}

void Respuesta(int I, int J, int X) {
  if (I == J || I < 0 || J < 0 || I >= 2 * COMI_N || J >= 2 * COMI_N) {
    COMI_quit(3, "Respuesta con indices invalidos");
  }
  if (COMI_A[I] != X || COMI_A[J] != X) {
    COMI_quit(3, "Respuesta con valor incorrecto");
  }
  if (X < 0 || X >= COMI_N || COMI_used[X]) {
    COMI_quit(4, "valor ya usado o fuera de rango");
  }
  COMI_used[X] = 1;
  COMI_ans++;
}

int main() {
  if (!(cin >> COMI_T >> COMI_N >> COMI_K)) return 0;
  if (COMI_N <= 0 || COMI_N > MAX_N) {
    COMI_quit(1, "N invalido");
  }
  for (int i = 0; i < COMI_N; i++) cin >> COMI_P[i];
  for (int i = 0; i < 2 * COMI_N; i++) cin >> COMI_A[i];
  COMI_flip = 0;
  COMI_ans = 0;
  memset(COMI_used, 0, sizeof(COMI_used));
  Resolver(COMI_T, COMI_N);
  if (COMI_ans != COMI_N) {
    COMI_quit(5, "no se llamo Respuesta exactamente N veces");
  }
  COMI_quit(0, "");
}
