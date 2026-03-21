#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

bool wouldCreateThree(int i, int j, vector<string>& cur) {
    char original = cur[i][j];
    cur[i][j] = '#';
    int n = cur.size();
    for (int k = 0; k <= n-3; k++) {
        if (cur[i][k] == '#' && cur[i][k+1] == '#' && cur[i][k+2] == '#') {
            cur[i][j] = original;
            return true;
        }
    }
    for (int k = 0; k <= n-3; k++) {
        if (cur[k][j] == '#' && cur[k+1][j] == '#' && cur[k+2][j] == '#') {
            cur[i][j] = original;
            return true;
        }
    }
    cur[i][j] = original;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        
        // Check initial grid for three consecutive black cells in any row or column
        bool foundThree = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-2; j++) {
                if (grid[i][j] == '#' && grid[i][j+1] == '#' && grid[i][j+2] == '#') {
                    foundThree = true;
                    break;
                }
            }
            if (foundThree) break;
        }
        if (!foundThree) {
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n-2; i++) {
                    if (grid[i][j] == '#' && grid[i+1][j] == '#' && grid[i+2][j] == '#') {
                        foundThree = true;
                        break;
                    }
                }
                if (foundThree) break;
            }
        }
        if (foundThree) {
            cout << "NO" << endl;
            continue;
        }
        
        // Check if there are any black cells
        bool hasBlack = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#') {
                    hasBlack = true;
                    break;
                }
            }
            if (hasBlack) break;
        }
        if (!hasBlack) {
            cout << "YES" << endl;
            continue;
        }
        
        // Initialize current grid and visited matrix
        vector<string> cur = grid;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        // Mark all initial black cells as visited and push to queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cur[i][j] == '#') {
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        
        // BFS to add white cells
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                if (vis[ni][nj]) continue;
                if (cur[ni][nj] == '.') {
                    if (!wouldCreateThree(ni, nj, cur)) {
                        cur[ni][nj] = '#';
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
        
        // Check connectivity of the final set of black cells
        vector<vector<bool>> comp(n, vector<bool>(n, false));
        int components = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] && !comp[i][j]) {
                    components++;
                    if (components > 1) break;
                    queue<pair<int, int>> qq;
                    qq.push({i, j});
                    comp[i][j] = true;
                    while (!qq.empty()) {
                        auto [x, y] = qq.front();
                        qq.pop();
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dirs[d][0];
                            int ny = y + dirs[d][1];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if (vis[nx][ny] && !comp[nx][ny]) {
                                comp[nx][ny] = true;
                                qq.push({nx, ny});
                            }
                        }
                    }
                }
            }
            if (components > 1) break;
        }
        
        if (components == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}