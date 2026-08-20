#include <iostream>
#include <vector>
using namespace std;

struct Cell {
    int cartulina; // número de capas de cartulina remaining
    vector<int> papers; // papeles agregados
};

int main() {
    int M, N, G, C, K;
    cin >> M >> N;
    cin >> G >> C;
    cin >> K;

    // Inicializar grid: N filas, M columnas.
    vector<vector<Cell>> grid(N, vector<Cell>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            grid[i][j].cartulina = G;
        }
    }

    // Procesar cada operación
    for (int k = 0; k < K; k++) {
        int Ci, Mi, Ni, Xi, Yi;
        cin >> Ci >> Mi >> Ni >> Xi >> Yi;

        for (int i = Xi; i < Xi + Ni; i++) {
            for (int j = Yi; j < Yi + Mi; j++) {
                // Verificar límites
                if (i < 0 || i >= N || j < 0 || j >= M) continue;

                if (Ci != -1) {
                    // Pegar: agregar papel
                    grid[i][j].papers.push_back(Ci);
                } else {
                    // Despegar
                    if (grid[i][j].cartulina > 0) {
                        grid[i][j].cartulina--;
                    } else {
                        if (!grid[i][j].papers.empty()) {
                            grid[i][j].papers.pop_back();
                        }
                    }
                }
            }
        }
    }

    // Imprimir
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!grid[i][j].papers.empty()) {
                cout << grid[i][j].papers.back() << " ";
            } else {
                if (grid[i][j].cartulina > 0) {
                    cout << C << " ";
                } else {
                    cout << -1 << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}