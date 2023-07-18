#include <iostream>
#include <vector>

using namespace std;

struct coordenada{
    int x, y;
}actual;

int n, m;
char cd[1001][1001];
vector<vector<int>> adj(1000001);
vector<bool> visited(1000001, 0);

int getposition(coordenada xd){
    int a = xd.x * m;
    int b = m - xd.y;
    int c = a - b;
    return c;   
}

void createconection(char m, coordenada Pos){
    coordenada next = Pos;
    if(m == 'N'){
        next.x--;
    }
    if(m == 'S'){
        next.x++;
    }
    if(m == 'E'){
        next.y++;
    }
    if(m == 'W'){
        next.y--;
    }
    if(next.x <= 0 || next.x > n || next.y <= 0 || next.y > m)return;

    int u = getposition(Pos);
    int v = getposition(next);
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(int i){
    visited[i] = 1; 
    for(auto e: adj[i]){
        if(!visited[e]){
            dfs(e);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> cd[i][j];
            actual = {i, j};
            createconection(cd[i][j], actual);
        }
    }
    int comp = 0;
    for(int i = 1; i <= n*m; ++i){
        if(!visited[i]){
            dfs(i);
            comp++;
        }
    }
    cout << comp << "\n";
}