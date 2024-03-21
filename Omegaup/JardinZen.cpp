#include <bits/stdc++.h>
#define MAX 1502
#define vector<vector<int>> Matrix
#define vector<vector<bool>> Matrib
using namespace std;

struct Point{
    int x, y;
    friend bool operator==(const Point &a, const Point &b){
        return a.x == b.x && a.y == b.y;
    };
};

int N, M;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
Matrib visited(MAX, vector<bool>(MAX, false));
Matrix G(MAX, vector<int>(MAX, 0));
queue<Point> Q;

bool is_corner(int i, int j){
    //Upper-right
    if(){

    }
    //Upper-left
    if(){

    }
    //Bottom-right
    if(){

    }
    //Bottom-left
    if(){

    }
}

int main(){
    ios_base::sync_with_stdio(0);   
    cin.tie(nullptr);
    cin >> N >> M;
    // Read the matrix
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> G[i][j];
        }
    }
    // Check corners
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(G[i][j] == 0 && is_corner(i, j) && !visited[i][j]){
                Q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while(!Q.empty()){
        Point next = Q.front();
        Q.pop();

        G[Q.x][Q.y] = 1;
        
    }
    return 0;
}