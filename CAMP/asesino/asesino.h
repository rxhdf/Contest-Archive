#include <bits/stdc++.h>
using namespace std;

// Asesino (cf-2022d2) — interfaz IOI para el concursante.
//
// encontrar_asesino(n): se llama una vez por caso, con n jugadores
//   numerados del 1 al n. Debe devolver el numero del Asesino.
//
// preguntar(i, j): la implementa el evaluador. Devuelve 1 si el jugador i
//   cree que el jugador j es Caballero, 0 si no. Puedes llamarla a lo mas
//   f(n) veces por caso (el minimo que garantiza encontrar al Asesino).

int encontrar_asesino(int n);
int preguntar(int i, int j);
