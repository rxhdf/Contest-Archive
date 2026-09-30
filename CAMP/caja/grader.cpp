#include "caja.h"
#include <bits/stdc++.h>
using namespace std;

const int COMI_max_consultas = 2500;

int COMI_h, COMI_w;
int COMI_br, COMI_bc;
int COMI_consultas = 0;

void COMI_error(const string& msg) {
    cerr << "ERROR: " << msg << "\n";
    exit(0);
}

pair<int,int> COMI_simular(const string& s) {
    int r = 0, c = 0;
    for (char ch : s) {
        int nr = r, nc = c;
        if (ch == '<') nc--;
        else if (ch == '>') nc++;
        else if (ch == '^') nr--;
        else if (ch == 'v' || ch == 'V') nr++;
        else COMI_error(string("caracter invalido '") + ch + "'");

        if (nr < 0 || nr >= COMI_h || nc < 0 || nc >= COMI_w)
            continue;
        if (nr == COMI_br && nc == COMI_bc)
            continue;
        r = nr; c = nc;
    }
    return {r, c};
}

pair<int,int> consultar(const string& s) {
    ++COMI_consultas;
    if (COMI_consultas > COMI_max_consultas)
        COMI_error("mas de 2500 consultas");
    if (s.empty())
        COMI_error("consulta vacia");
    if ((int)s.size() > 20000)
        COMI_error("consulta demasiado larga");
    return COMI_simular(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> COMI_h >> COMI_w >> COMI_br >> COMI_bc))
        COMI_error("no se pudo leer H W r c");

    if (COMI_h < 1 || COMI_h > 50 || COMI_w < 1 || COMI_w > 50)
        COMI_error("H o W fuera de rango");
    if (COMI_br < 0 || COMI_br >= COMI_h || COMI_bc < 0 || COMI_bc >= COMI_w)
        COMI_error("posicion de la caja fuera de la cuadricula");
    if (COMI_br == 0 && COMI_bc == 0)
        COMI_error("la caja no puede estar en (0, 0)");

    auto [r, c] = encontrar_caja(COMI_h, COMI_w);

    if (r == COMI_br && c == COMI_bc) {
        cout << "Correcto\n";
        cout << "consultas=" << COMI_consultas << "\n";
    } else {
        cout << "Incorrecto\n";
        cout << "caja=(" << COMI_br << ", " << COMI_bc << "), devolviste (" << r << ", " << c << ")\n";
    }
    return 0;
}
