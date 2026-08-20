#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
    int R, C;
    cin >> R >> C;
    
    vector<vector<int>> tablero(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> tablero[i][j];
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int color = (j + (i % C)) % C + 1;
            cout << color;
            if (j < C - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}