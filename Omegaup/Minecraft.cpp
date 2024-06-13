#include <bits/stdc++.h>
#define Point pair<int, int>
#define Node pair<int, Point>
#define Matrix vector<vector<char>>
using namespace std;

vector<int> f = {1, -1, 0, 0};
vector<int> c = {0, 0, -1, 1};
Matrix m (600, vector<char>(600, '#'));
int N, M;
Point In, Fin;

bool valid(int x, int y){
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

int bfs(){
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(make_pair(0, In));
    m[In.first][In.second] = '#';
    while(!pq.empty()){
        Node actual = pq.top();
        pq.pop();
        int delay = actual.first;
        Point p = actual.second;
        for(int i = 0; i < 4; ++i){
            int x = p.first + f[i];
            int y = p.second + c[i];
            if(x == Fin.first && y == Fin.second){
                if(m[x][y] == '.'){
                    return delay + 1;
                }else{
                  return delay + m[x][y] - '0' + 1;
                }
                
            }
            if(!valid(x, y) || m[x][y] == '#')continue;
            if(m[x][y] == '.'){
              pq.push({delay + 1, make_pair(x, y)});
            }else{
              pq.push({delay + m[x][y] - '0' + 1, make_pair(x, y)});
            }
            m[x][y] = '#';
            
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    cin >> In.first >> In.second;
    cin >> Fin.first >> Fin.second;

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> m[i][j];
        }
    }
    cout << bfs() << "\n";
    return 0;
}