#include <bits/stdc++.h>
#include "combo.h"

int COMI_N;
std::string COMI_S;
std::vector<int> COMI_fall;
int COMI_consultas = 0;

void COMI_error(std::string COMI_mensaje) {
    std::cerr << "ERROR: " << COMI_mensaje << "\n";
    std::cout << "Incorrecto\n" << COMI_mensaje << "\n";
    exit(0);
}

int presionar(std::string p) {
    ++COMI_consultas;
    if (COMI_consultas > 8000)
        COMI_error("mas de 8000 consultas");
    if ((int)p.size() > 4 * COMI_N)
        COMI_error("consulta de longitud " + std::to_string(p.size()) + " > 4N");
    for (char c : p)
        if (c != 'A' && c != 'B' && c != 'X' && c != 'Y')
            COMI_error(std::string("la consulta contiene un caracter invalido '") + c + "'");
    int r = 0, k = 0;
    for (char c : p) {
        while (k && c != COMI_S[k]) k = COMI_fall[k - 1];
        if (c == COMI_S[k]) k++;
        if (k > r) r = k;
        if (k == COMI_N) break;
    }
    return r;
}

int main() {
    if (!(std::cin >> COMI_N))
        COMI_error("no se pudo leer N");
    if (COMI_N < 1 || COMI_N > 2000)
        COMI_error("N fuera de rango");
    if (!(std::cin >> COMI_S))
        COMI_error("no se pudo leer S");
    if ((int)COMI_S.size() != COMI_N)
        COMI_error("|S| debe ser exactamente N");
    for (char c : COMI_S)
        if (c != 'A' && c != 'B' && c != 'X' && c != 'Y')
            COMI_error("S contiene un caracter invalido");
    for (int i = 1; i < COMI_N; i++)
        if (COMI_S[i] == COMI_S[0])
            COMI_error("el primer caracter de S se repite");

    COMI_fall.assign(COMI_N, 0);
    for (int i = 1, k = 0; i < COMI_N; i++) {
        while (k && COMI_S[i] != COMI_S[k]) k = COMI_fall[k - 1];
        if (COMI_S[i] == COMI_S[k]) k++;
        COMI_fall[i] = k;
    }

    std::string COMI_T = adivinar_combo(COMI_N);
    if (COMI_T != COMI_S)
        COMI_error("la respuesta no es la secuencia secreta");

    std::cout << "Correcto\n";
    std::cout << "total de consultas=" << COMI_consultas << "\n";
    return 0;
}
