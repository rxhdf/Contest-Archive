#include <bits/stdc++.h>
using namespace std;

struct node{
    int X, Y;
    int depth = 0;
};

int N, X, Y, C, CL = 1, depth = 0;
queue<node> q;
vector<short int> f = {1, 0 -1, 0};
vector<short int> c = {0, 1, 0, -1};

void bfs(){
    q.push({X, Y, 0});
    while(!q.empty()){
        auto AC = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = AC.X + f[i];
            int ny = AC.Y + c[i];
            int depth = AC.depth + 1;
            if(CL >= C) return;
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                CL++;
                q.push({nx, ny, depth});
            }
        }   
        depth = q.front().depth;
    }
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(nullptr);
    cin >> N >> X >> Y >> C;    
    bfs();
    cout << depth << "\n";
    return 0;
}