#include <bits/stdc++.h>
#include "navegacion.h"

int COMI_R, COMI_C, COMI_tr, COMI_tc;
std::vector<std::vector<int>> COMI_col;

void COMI_error(std::string COMI_mensaje) {
    std::cerr << "ERROR: " << COMI_mensaje << "\n";
    std::cout << "Incorrecto\n" << COMI_mensaje << "\n";
    exit(0);
}

int COMI_at(int r, int c) {
    return (r >= 0 && r < COMI_R && c >= 0 && c < COMI_C) ? COMI_col[r][c] : -1;
}

int COMI_dist(int r, int c) {
    return abs(r - COMI_tr) + abs(c - COMI_tc);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (!(std::cin >> COMI_R >> COMI_C >> COMI_tr >> COMI_tc))
        COMI_error("no se pudo leer R C tr tc");
    if (COMI_R < 1 || COMI_R > 20 || COMI_C < 1 || COMI_C > 20)
        COMI_error("R o C fuera de rango");
    if (COMI_tr < 0 || COMI_tr >= COMI_R || COMI_tc < 0 || COMI_tc >= COMI_C)
        COMI_error("T fuera de rango");

    COMI_col = anna(COMI_R, COMI_C, COMI_tr, COMI_tc);
    if ((int)COMI_col.size() != COMI_R)
        COMI_error("anna no devolvio R filas");
    int COMI_maxc = 0;
    for (int r = 0; r < COMI_R; r++) {
        if ((int)COMI_col[r].size() != COMI_C)
            COMI_error("anna no devolvio C columnas en la fila " + std::to_string(r));
        for (int c = 0; c < COMI_C; c++) {
            if (COMI_col[r][c] < 0)
                COMI_error("anna uso un color negativo");
            COMI_maxc = std::max(COMI_maxc, COMI_col[r][c]);
        }
    }

    // Bruno desde TODAS las celdas de arranque, con las consultas de
    // todos los caminantes intercaladas (un bruno correcto no usa
    // memoria, asi que la intercalacion no lo afecta).
    struct COMI_W { int r, c, steps; bool done; };
    std::vector<COMI_W> COMI_ws;
    for (int r = 0; r < COMI_R; r++)
        for (int c = 0; c < COMI_C; c++)
            COMI_ws.push_back({r, c, 0, false});
    int COMI_restantes = (int)COMI_ws.size();
    const int COMI_tope = COMI_R * COMI_C;
    const int COMI_dr[4] = {-1, 1, 0, 0}, COMI_dc[4] = {0, 0, -1, 1};

    while (COMI_restantes > 0) {
        for (auto &w : COMI_ws) {
            if (w.done) continue;
            int r = w.r, c = w.c;
            char resp = bruno(COMI_col[r][c], COMI_at(r - 1, c),
                              COMI_at(r + 1, c), COMI_at(r, c - 1),
                              COMI_at(r, c + 1));
            if (resp == 'H') {
                if (r != COMI_tr || c != COMI_tc)
                    COMI_error("bruno se planto en (" + std::to_string(r) +
                               "," + std::to_string(c) + "), T=(" +
                               std::to_string(COMI_tr) + "," +
                               std::to_string(COMI_tc) + ")");
                w.done = true;
                COMI_restantes--;
                continue;
            }
            int d = (resp == 'N') ? 0 : (resp == 'S') ? 1
                  : (resp == 'O') ? 2 : (resp == 'E') ? 3 : -1;
            if (d < 0)
                COMI_error(std::string("respuesta invalida '") + resp + "'");
            int nr = r + COMI_dr[d], nc = c + COMI_dc[d];
            if (nr < 0 || nr >= COMI_R || nc < 0 || nc >= COMI_C)
                COMI_error("bruno movio fuera del tablero");
            if (COMI_dist(nr, nc) != COMI_dist(r, c) - 1)
                COMI_error("el paso no acorta la distancia a T");
            w.r = nr; w.c = nc;
            if (++w.steps > COMI_tope)
                COMI_error("ciclo: mas de R*C pasos");
        }
    }

    std::cout << "Correcto\n";
    std::cout << "maxcolor=" << COMI_maxc << "\n";
    return 0;
}
