#include <bits/stdc++.h>

#define MAXN 1002

using namespace std;

struct nodo{
    int x, y;
    int saltos = 0;
};

int M, N, F, D;
nodo H, R;
vector<int> f(4);
vector<int> c(4);
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, 0));
queue<nodo> q;

int BFS(){
    q.push(R);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        if(u.x == H.x && u.y == H.y)return u.saltos;
        for(int i = 0; i < 4; ++i){
            auto next = u;
            next.x += f[i];
            next.y += c[i];
            next.saltos++;
            if(next.x < 0 || next.x >= M || next.y < 0 || next.y >= N)continue;
            if(visited[next.x][next.y])continue;
            visited[next.x][next.y] = 1;
            q.push(next);
        }        
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> F >> D >> R.x >> R.y >> H.x >> H.y;
    //Iniciailzamos vectores
    f[0] = D;
    c[0] = F;
    f[1] = F*-1;
    c[1] = D;
    f[2] = D*-1;
    c[2] = F*-1;
    f[3] = F;
    c[3] = D*-1;
    //BFS chida
    int answer = BFS();
    cout << answer << "\n";
    return 0;
}