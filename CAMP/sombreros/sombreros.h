#include <bits/stdc++.h>
using namespace std;

// Sombreros Chilenos — interfaz IOI para el concursante.
//
// Hay 100 personas con sombreros; el sombrero de cada uno tiene un color
// entre 1 y 100 (puede repetirse). Cada persona ve los sombreros de las
// demas pero no el suyo. Debe adivinar su color: basta con que AL MENOS
// UNA persona acierte.
//
// adivinar(A, id): se llama una vez por persona. A tiene 100 enteros: el
//   color del sombrero de cada persona, con un 0 en tu posicion (la que
//   no puedes ver). id es tu posicion. Devuelve tu color adivinado
//   (1-100).

int adivinar(vector<int> A, int id);
