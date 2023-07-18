#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x, y, steps = 0;
};

int n, m, k;
vector<int> f(11);
vector<int> c(11);
int visited[1001][1001];
Node inicio;
Node Base;
queue<Node> cola;
int solve(){
    cola.push(inicio);
    visited[inicio.x][inicio.y] = 1;
    while(!cola.empty()){
        Node actual = cola.front();
        cola.pop();
        if(actual.x == Base.x && actual.y == Base.y)return actual.steps;
        for(int i = 0; i < k; ++i){
            Node next = actual;
            next.x += f[i];
            next.y += c[i];
            next.steps++;
            if(next.x <= 0 || next.x > n || next.y <= 0 || next.y > m)continue;
            if(visited[next.x][next.y])continue;
            
            visited[next.x][next.y] = 1;
            cola.push(next);
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(visited, 0, sizeof(visited));
    cin >> n >> m >> k;
    cin >> inicio.x >> inicio.y;
    cin >> Base.x >> Base.y;
    for(int i = 0; i < k; ++i){
        cin >> f[i] >> c[i];
    }
    cout << solve() << "\n";
    return 0;
}