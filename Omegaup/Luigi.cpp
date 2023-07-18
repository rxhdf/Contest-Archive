#include <bits/stdc++.h>

using namespace std;

struct Pos{
    int x, y;
    friend bool operator==(Pos a, Pos b){
        return a.x == b.x && a.y == b.y;
    }
    friend bool operator<(Pos a, Pos b){    
        if (a.x == b.x){
            return a.y < b.y;
        }
        return a.x < a.x;
    }
}M, L, S;

struct Nodo{
    Pos mario, luigi;
    int seg = 0;
};


int n;
char mapa[51][51];
int visitados[51][51][51][51];
queue<Nodo> cola;
vector<int> f = {0, -1, 0, 1};
vector<int> c = {1, 0, -1, 0};
int solve(Pos Mario, Pos Luigi, Pos Salida){
    Nodo inicio = {Mario, Luigi, 0};
    cola.push(inicio);
    visitados[inicio.mario.x][inicio.mario.y][inicio.luigi.x][inicio.luigi.y] = -1;
    while(!cola.empty()){
        Nodo actual = cola.front();
        cola.pop();
        if(actual.mario == Salida && actual.luigi == Salida){
            return actual.seg;
        }
        for(int i = 0; i < 4; ++i){
            Pos siguiente = actual.mario;
            siguiente.x += f[i];
            siguiente.y += c[i];
            if(siguiente.x < 0 || siguiente.x > n || siguiente.y < 0 || siguiente.y > n)continue;
            if(mapa[siguiente.x][siguiente.y] == '#')continue;
            if(mapa[siguiente.x][siguiente.y] == '*'){
                if(mapa[actual.luigi.x][actual.luigi.y] != 'B')continue;
            }
            if(visitados[siguiente.x][siguiente.y][actual.luigi.x][actual.luigi.y] == -1)continue;
        
            visitados[siguiente.x][siguiente.y][actual.luigi.x][actual.luigi.y] = -1;
            Nodo nuevo = {siguiente, actual.luigi, actual.seg + 1};
            cola.push(nuevo);
        }
        for(int i = 0; i < 4; ++i){
            Pos siguiente = actual.luigi;
            siguiente.x += f[i];
            siguiente.y += c[i];
            if(siguiente.x < 0 || siguiente.x > n || siguiente.y < 0 || siguiente.y > n)continue;
            if(mapa[siguiente.x][siguiente.y] == '#')continue;
            if(mapa[siguiente.x][siguiente.y] == '*'){
                if(mapa[actual.mario.x][actual.mario.y] != 'B')continue;
            }
            if(visitados[siguiente.x][siguiente.y][actual.mario.x][actual.mario.y] == -1)continue;
            visitados[siguiente.x][siguiente.y][actual.mario.x][actual.mario.y] = -1;
            Nodo nuevo = {actual.mario, siguiente, actual.seg + 1};
            cola.push(nuevo);
        }
    }
    return -1;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> mapa[i][j];
            if(mapa[i][j] == 'M')M.x = i, M.y = j;
            if(mapa[i][j] == 'L')L.x = i, L.y = j;
            if(mapa[i][j] == 'S')S.x = i, S.y = j;
        }
    }
    cout << solve(M, L, S) << "\n";
    return 0;
}