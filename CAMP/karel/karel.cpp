#include "karel.h"
#include <bits/stdc++.h>
#define norte 2
#define sur 4
#define este 1
#define oeste 3

using namespace std;

struct esquina{
    int x, y, wallO;
};

bool walls [67][67][5];
int tam;
vector<pair<int, int>> movs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int borde(pair<int, int> karel, int n){
    int i = karel.first, j = karel.second;
    int x, y;
    x = y = ((n + 1) / 2);
    if((i == x - 4 && j == y - 4) || (i == x + 4 && j == y - 4)) return 1;
    else if((i == x - 4 && j == y + 4) || (i == x + 4 && j == y + 4)) return 3;
    else {
        if(i == x - 4) return 2;
        else if(i == x + 4) return 4;
        else if(j == (y - 4)) return 1;
        else if(j == y + 4) return 3;
        else return 0;
    }
}

bool linea_horizontal_cerrada(int mid_f, int min_c, int max_c){
    for(int c = min_c; c <= max_c; ++c){
        if(!walls[mid_f][c][4]) return false;
    }
    return true;
}   

bool linea_vertical_cerrada(int mid_c, int min_f, int max_f){
    for(int f = min_f; f <= max_f; ++f){
        if(!walls[f][mid_c][1]) return false;
    }
    return true;
}

void actualizar_muros_bidireccionales(int x, int y, int d){
    if(x < 1 || x > tam || y < 1 || y > tam) return;
    if(walls[x][y][d]) return;

    walls[x][y][d] = true;
    poner_muro(x, y, d);

    int nx = x + movs[d - 1].first;
    int ny = y + movs[d - 1].second;
    int nop = ((d + 1) % 4) + 1;

    if(nx >= 1 && nx <= tam && ny >= 1 && ny <= tam){
        walls[nx][ny][nop] = true;
    }
}

// CORRECCIÓN: Garantiza que SIEMPRE se coloque 1 muro válido por turno para evitar violar las reglas
void colocar_muro_seguro(int x, int y, int d) {
    if(x >= 1 && x <= tam && y >= 1 && y <= tam && !walls[x][y][d]){
        actualizar_muros_bidireccionales(x, y, d);
        return;
    }
    // Muro basura de reserva si la petición fue inválida, estaba fuera de límites o el muro ya existía
    for(int i = 1; i <= tam; ++i){
        for(int j = 1; j <= tam; ++j){
            for(int w = 1; w <= 4; ++w){
                if(!walls[i][j][w]){
                    actualizar_muros_bidireccionales(i, j, w);
                    return;
                }
            }
        }
    }
}

void dividir(int &karelx, int &karely, int min_x, int max_x, int min_y, int max_y){
    while(true){
        int vertical = max_x - min_x + 1;
        int horizontal = max_y - min_y + 1;

        if(vertical > 1){
            int mid_x = min_x + (vertical / 2) - 1;
            if(linea_horizontal_cerrada(mid_x, min_y, max_y)){
                if(karelx <= mid_x) max_x = mid_x;
                else min_x = mid_x + 1;
                vertical = max_x - min_x + 1;
            }
        }
        if(horizontal > 1){
            int mid_y = min_y + (horizontal / 2) - 1;
            if(linea_vertical_cerrada(mid_y, min_x, max_x)){
                if(karely <= mid_y) max_y = mid_y;
                else min_y = mid_y + 1;
                horizontal = max_y - min_y + 1;
            }
        }

        int targetX = -1, targetY = -1, targetW = -1;
        for(int i = 0; i < 4; ++i){
            int nx = karelx + movs[i].first;
            int ny = karely + movs[i].second;
            if(!walls[karelx][karely][i + 1]){
                if(nx > max_x || nx < min_x || ny > max_y || ny < min_y){
                    targetX = karelx; targetY = karely; targetW = i + 1;
                    break;
                }
            }
        }
        
        if(targetX == -1){
            if(vertical >= horizontal && vertical > 1){
                int mid_x = min_x + (vertical / 2) - 1;
                for(int i = min_y; i <= max_y; ++i){
                    if(karelx <= mid_x && !walls[mid_x][i][4]){
                        targetX = mid_x; targetY = i; targetW = 4; break;
                    }
                    else if(karelx > mid_x && !walls[mid_x + 1][i][2]){
                        targetX = mid_x + 1; targetY = i; targetW = 2; break;
                    }
                }
            }
            else if(horizontal > 1){
                int mid_y = min_y + (horizontal / 2) - 1;
                for(int i = min_x; i <= max_x; ++i){
                    if(karely <= mid_y && !walls[i][mid_y][1]){
                        targetY = mid_y; targetX = i; targetW = 1; break;
                    }
                    else if(karely > mid_y && !walls[i][mid_y + 1][3]){
                        targetY = mid_y + 1; targetX = i; targetW = 3; break;
                    }
                }
            }
        }
        
        if(targetX == -1){
            for(int i = 1; i <= 4; ++i){
                if(!walls[karelx][karely][i]){
                    targetW = i; targetX = karelx; targetY = karely; break;
                }
            }
        }

        // CORRECCIÓN: Automáticamente despliega muro objetivo, o un muro basura si targetX es -1
        colocar_muro_seguro(targetX, targetY, targetW);
        
        int mov = recibir_movimiento();
        if(mov == 0) break;

        karelx += movs[mov - 1].first;
        karely += movs[mov - 1].second;
    }
}

void jugar(int n) {
    tam = n;
    memset(walls, false, sizeof(walls));
    
    // CORRECCIÓN: Registrar el perímetro para evitar construir muros sobre orillas
    for(int i = 1; i <= n; ++i){
        walls[1][i][2] = true;
        walls[i][n][1] = true;
        walls[i][1][3] = true;
        walls[n][i][4] = true;
    }

    if(n >= 9){
        int x, y, usedWall = 0, x2, y2;
        x = y = x2 = y2 = ((n + 1) / 2);
        set<pair<int, pair<int, int>>> missingWallsEdges;
        vector<esquina> esquinas = {{x - 4, y - 4, norte}, {x - 4, y + 4, norte}, {x + 4, y - 4, sur}, {x + 4, y + 4, sur}};
        
        int movement;
        for(int i = 0; i < 4; ++i){
            colocar_muro_seguro(esquinas[i].x, esquinas[i].y, esquinas[i].wallO);
            usedWall++;
            movement = recibir_movimiento();
            if(movement == 0) return;
            x += movs[movement - 1].first; y += movs[movement - 1].second;
        }
        
        // Almacenar bordes norte-sur faltantes (ignorando si quedan fuera de la tabla)
        for(int i = y2 - 4; i <= y2 + 4; ++i) if(x2 - 4 >= 1 && !walls[x2 - 4][i][norte]) missingWallsEdges.insert({x2 - 4,{i, norte}});
        for(int i = y2 - 4; i <= y2 + 4; ++i) if(x2 + 4 <= n && !walls[x2 + 4][i][sur]) missingWallsEdges.insert({x2 + 4,{i, sur}});
        // Almacenar bordes este-oeste faltantes
        for(int i = x2 - 4; i <= x2 + 4; ++i) if(y2 - 4 >= 1 && !walls[i][y2 - 4][oeste]) missingWallsEdges.insert({i,{y2 - 4, oeste}});
        for(int i = x2 - 4; i <= x2 + 4; ++i) if(y2 + 4 <= n && !walls[i][y2 + 4][este]) missingWallsEdges.insert({i,{y2 + 4, este}});
        
        bool encerrado = false;
        pair<int, int> karel = {x, y};

        // Helper para extraer de manera segura el muro faltante sin accesos inválidos
        auto pop_missing_wall = [&]() {
            if(!missingWallsEdges.empty()){
                auto it = missingWallsEdges.begin();
                int nf = it->first, nc = it->second.first, nd = it->second.second;
                missingWallsEdges.erase(it);
                if(missingWallsEdges.empty()) encerrado = true;
                colocar_muro_seguro(nf, nc, nd);
            } else {
                colocar_muro_seguro(-1, -1, -1);
            }
        };

        while(movement != 0 && !encerrado){
            int b = borde(karel, n);
            if(b == 2){
                if(walls[karel.first][karel.second][norte]) pop_missing_wall();
                else {
                    pair<int, pair<int, int>> newall = {karel.first, {karel.second, norte}};
                    missingWallsEdges.erase(newall);
                    if(missingWallsEdges.empty()) encerrado = true;
                    colocar_muro_seguro(karel.first, karel.second, norte);
                }
            }
            else if(b == 4){
                if(walls[karel.first][karel.second][sur]) pop_missing_wall();
                else {
                    pair<int, pair<int, int>> newall = {karel.first, {karel.second, sur}};
                    missingWallsEdges.erase(newall);
                    if(missingWallsEdges.empty()) encerrado = true;
                    colocar_muro_seguro(karel.first, karel.second, sur);
                }
            }
            else if(b == 1){
                if(walls[karel.first][karel.second][oeste]) pop_missing_wall();
                else {
                    pair<int, pair<int, int>> newall = {karel.first, {karel.second, oeste}};
                    missingWallsEdges.erase(newall);
                    if(missingWallsEdges.empty()) encerrado = true;
                    colocar_muro_seguro(karel.first, karel.second, oeste);
                }
            }
            else if(b == 3){
                if(walls[karel.first][karel.second][este]) pop_missing_wall();
                else {
                    pair<int, pair<int, int>> newall = {karel.first, {karel.second, este}};
                    missingWallsEdges.erase(newall);
                    if(missingWallsEdges.empty()) encerrado = true;
                    colocar_muro_seguro(karel.first, karel.second, este);
                }
            } else {
                pop_missing_wall();
            }
            
            movement = recibir_movimiento();
            if(movement == 0) break;
            karel.first += movs[movement - 1].first;
            karel.second += movs[movement - 1].second;
        }
        
        if(movement == 0) return;
        dividir(karel.first, karel.second, x2 - 4, x2 + 4, y2 - 4, y2 + 4);
        
    } else {
        // CORRECCIÓN: Lógica de escape de Karel (n < 9)
        int f, c, d;
        int x = ((n + 1) / 2), y = ((n + 1) / 2);
        
        while(true){
            recibir_muro(f, c, d);
            actualizar_muros_bidireccionales(f, c, d);
            bool moved = false;
            
            for(int i = 0; i < 4; ++i){
                if(!walls[x][y][i + 1]){
                    mover(i + 1);
                    x += movs[i].first;
                    y += movs[i].second;
                    moved = true;
                    break; // Solo da UN paso válido por turno.
                }
            }
            // Si quedó atrapado o si salió de los límites de la matriz (ganó)
            if(!moved || x < 1 || x > n || y < 1 || y > n) break;
        }
    } 
}