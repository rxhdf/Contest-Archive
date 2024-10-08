#include <bits/stdc++.h>
#define y second 
#define x first
using namespace std;

int y = 0;
int N;
string S;
vector<vector<int>> graph;
//Mapa para detectar los nodos individuales
map<pair<int, int>, int> MP;

//movimientos por la matriz
vector<short> f = {1, 0, -1, 0};
vector<short> c = {0, -1, 0, 1};
short ans = 1;
void BFS(int start){
    queue<int> q;
    vector<bool> visited(N + 1, 0);
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int actual = q.front();
        q.pop();
        //cout << actual << "-";
        ++ans;
        for(auto next: graph[actual]){
            if(next == y)return;
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    //Mapear los nodos segun los movimientos
    graph.resize(N + 1);
    
    pair<int, int> start = {0, 0};
    for(int i = 0; i < N; ++i){
        if(S[i] == 'L'){
            start.y--;
        }
        else if(S[i] == 'R'){
            start.y++;
        }
        else if(S[i] == 'U'){
            start.x--;
        }
        else if(S[i] == 'D'){
            start.x++;
        }
        if(i == N - 1){
            if(MP[make_pair(start.x, start.y)] != 0)continue;
            else MP[make_pair(start.x, start.y)] = i + 1;
            y = i + 1;
            break;
        }
        //cout << y << "last\n";
        if(MP[make_pair(start.x, start.y)] != 0)continue;
        else MP[make_pair(start.x, start.y)] = i + 1;

        //cout << start.x << " " << start.y << "\n";
    }
    //for(auto e: MP)cout << e.first.first << " " << e.first.second << " " << e.second << "\n"; 
    //Construir grafo para ejecutar BFS
    //si BFS(graph) < N entonces existe un camino mas corto y por lo tanto no hay esperanza
    for(auto e: MP){
        //Revisar por cada casilla adyacente si existe una conexion entre ambos nodos
        for(int i = 0; i < 4; ++i){
            //
            if(MP.find(make_pair(e.first.first + f[i], e.first.second + c[i])) != MP.end()){
                //cout << e.first.first + f[i] << " " << e.first.second + c[i] << " " << e.second << "\n";
                int a = e.second, b = MP[make_pair(e.first.first + f[i], e.first.second + c[i])];
                //cout << a << " " << b << " There is a connect2ion\n";
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
        }
        //cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
    }   
    BFS(1);
    if(ans < N){
        cout << "N\n";
    }else cout << "S\n";

    return 0;
}