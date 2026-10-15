#include <bits/stdc++.h>
#include "stalker.h"
using namespace std;

static const long long COMI_LIM = 1000000000000000000LL;
static const int COMI_MAX_CICLOS = 100;

static long long COMI_pizarra;
static vector<long long> COMI_cuaderno;
static int COMI_llamadas;
static bool COMI_terminado;
static int COMI_respuesta;
static long long COMI_valor_maximo;

static void COMI_error(const char* COMI_msg) {
    printf("Incorrecto: %s\n", COMI_msg);
    exit(0);
}

void anotar(long long b, long long x) {
    if (COMI_terminado) {
        COMI_error("llamaste a una funcion despues de declarar una respuesta");
    }
    if (++COMI_llamadas > 1) {
        COMI_error("llamaste a mas de una funcion en una misma entrada al cuarto");
    }
    if (b < -COMI_LIM || b > COMI_LIM) {
        COMI_error("b fuera de [-10^18, 10^18]");
    }
    if (x < -COMI_LIM || x > COMI_LIM) {
        COMI_error("x fuera de [-10^18, 10^18]");
    }

    COMI_pizarra = b;
    COMI_valor_maximo = max(COMI_valor_maximo, b < 0 ? -b : b);
    COMI_cuaderno.push_back(x);
}

void responder(int n) {
    if (COMI_terminado) {
        COMI_error("llamaste a una funcion despues de declarar una respuesta");
    }
    if (++COMI_llamadas > 1) {
        COMI_error("llamaste a mas de una funcion en una misma entrada al cuarto");
    }

    COMI_terminado = true;
    COMI_respuesta = n;
}

int main() {
    int COMI_m;
    if (scanf("%d", &COMI_m) != 1) {
        COMI_error("la entrada no contiene m");
    }

    COMI_pizarra = 0;
    COMI_terminado = false;
    COMI_valor_maximo = 0;
    vector<vector<long long>> COMI_cuadernos(COMI_m);

    int COMI_K = 0;
    while (!COMI_terminado) {
        if (++COMI_K > COMI_MAX_CICLOS) {
            COMI_error("la estrategia supero el limite de 100 ciclos");
        }
        for (int COMI_i = 0; COMI_i < COMI_m && !COMI_terminado; COMI_i++) {
            COMI_cuaderno = COMI_cuadernos[COMI_i];
            COMI_llamadas = 0;
            stalker(COMI_pizarra, COMI_cuaderno);
            COMI_cuadernos[COMI_i] = COMI_cuaderno;
            if (COMI_llamadas == 0) {
                COMI_error("un stalker termino su entrada sin llamar a ninguna funcion");
            }
        }
    }

    if (COMI_respuesta != COMI_m) {
        printf("Incorrecto: declaraste %d miembros, pero son %d\n", COMI_respuesta, COMI_m);
    } else {
        double COMI_pts = 80.0 * pow(1.02, -sqrt(max(0.0, (double)COMI_valor_maximo * COMI_valor_maximo * COMI_K - 40.0))) + 20.0;
        printf("Correcto. Ciclos: %d, maximo en pizarra: %lld, puntaje: %.2f\n", COMI_K, COMI_valor_maximo, COMI_pts);
    }
}