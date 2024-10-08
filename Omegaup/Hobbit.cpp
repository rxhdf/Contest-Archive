#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 61
#define INF 10000000

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<vector<int>>> dp(MAX, vector<vector<int>>(MAX, vector<int>(5, INF)));
    vector<vector<int>> CM(MAX, vector<int>(MAX, 0));

    // Leer la matriz CM
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            cin >> CM[i][j];
        }
    }

    // Inicializar el dp con los valores iniciales de la matriz CM
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            dp[i][j][CM[i][j]] = 1;
        }
    }

    // Inicializar el punto de partida con 0
    for(int k = 1; k <= 3; ++k) {
        dp[1][1][k] = 0;
    }

    // Programación dinámica para calcular el costo mínimo
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            for(int k = 1; k <= 3; ++k) {
                if (i > 1) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 1);  // Desde arriba
                if (j > 1) dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k] + 1);  // Desde la izquierda
            }
        }
    }

    // Imprimir la matriz dp para cada tipo
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            for(int k = 1; k <= 3; ++k) {
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
