#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> dy = {1, -1, 0, -1, 1, 0, -1, 1};
    while(tt--){
        int n;
        cin >> n;
        vector<vector<char>> maze(2, vector<char>(n));
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < n; ++j){
                cin >> maze[i][j];
            }
        }

        vector<vector<bool>> visited(2, vector<bool>(n, false));

        auto BFS = [&](pair<int, int> start){
            queue<pair<int, int>> q;
            visited[start.first][start.second] = true;
            q.push(start);
            while(!q.empty()){
                pair<int, int> actual = q.front();
                q.pop();
                for(int i = 0; i < 8; ++i){
                    int nx = actual.first + dx[i];
                    int ny = actual.second + dy[i];
                    if(nx >= 0 && nx < 2 && ny >= 0 && ny < n){
                        if(!visited[nx][ny] && maze[nx][ny] == '0'){
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        };  
        BFS({0, 0});

        if(visited[1][n - 1]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}