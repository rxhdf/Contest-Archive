#include <bits/stdc++.h>
#define ARRIBA 0
#define ABAJO 1
#define DERECHA 2
#define IZQUIERDA 3
using namespace std;

struct Pos{
    int x, y, steps = 0;
    friend bool operator<(const Pos &a, const Pos &b){
        return a.steps < b.steps;
    }
};

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    Pos A, B;
    vector<vector<char>> grid(N + 1, vector<char>(M + 1));
    vector<vector<vector<int>>> Precalculo(4, vector<vector<int>>(N + 1, vector<int>(M + 1)));
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> grid[i][j];
            if(grid[i][j] == 'X'){
                A = {i, j, 0};
            }
            if(grid[i][j] == 'O'){
                B = {i, j, 0};
            }
            if(grid[i][j] != '#'){
                Precalculo[ARRIBA][i][j] = Precalculo[ARRIBA][i - 1][j] + 1;
                Precalculo[IZQUIERDA][i][j] = Precalculo[IZQUIERDA][i][j - 1] + 1; 
            }
        }
    }
    for(int i = N; i >= 1; --i){
        for(int j = M; j >= 1; --j){
            if(grid[i][j] != '#'){
                Precalculo[ABAJO][i][j] = Precalculo[ABAJO][i + 1][j] + 1;
                Precalculo[DERECHA][i][j] = Precalculo[DERECHA][i][j + 1] + 1;
            }
        }
    }
    
    priority_queue<Pos> pq;
    vector<int> f  = {};
    vector<int> c = {};
    auto bfs = [&](){
        pq.push(A);
        while(!pq.empty()){
            Pos ac = pq.top();
            pq.pop();
            for(int i = 0; i < 4; ++i){
                int nx = ac.x + f[i];
                int ny = ac.y + c[i];
                if(nx <= 0 || nx > N || ny <= 0 || ny > M)continue;
                if(grid[nx][ny] == '#'){
                    for(int i = 0; i < 4; ++i){

                    }
                }else{
                    
                }
            }
        }
    };
    return 0;
}