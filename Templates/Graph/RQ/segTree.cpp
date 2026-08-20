#include <bits/stdc++.h>
#define ll long long
using namespace std;

char grid[1001][1001];
bool visited[1001][1001];
int n, m;

vector<int> dx = {1, 0, -1, 0, 1, -1, -1, 1};
vector<int> dy = {0, 1, 0, -1, 1, -1, 1, -1};

bool esquina(int x, int y){
    if (grid[x][y] == '.') return false;

    if (x > 1 && y > 1 &&
        grid[x - 1][y - 1] == '.' &&
        grid[x - 1][y] == '.' &&
        grid[x][y - 1] == '.') return true;

    if (x > 1 && y < m &&
        grid[x - 1][y + 1] == '.' &&
        grid[x - 1][y] == '.' &&
        grid[x][y + 1] == '.') return true;

    if (x < n && y < m &&
        grid[x + 1][y] == '.' &&
        grid[x][y + 1] == '.' &&
        grid[x + 1][y + 1] == '.') return true;

    if (x < n && y > 1 &&
        grid[x][y - 1] == '.' &&
        grid[x + 1][y - 1] == '.' &&
        grid[x + 1][y] == '.') return true;

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    queue<pair<int,int>> q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (esquina(i, j) && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto actual = q.front();
        q.pop();

        int x = actual.first;
        int y = actual.second;

        grid[x][y] = '.';

        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && esquina(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}
