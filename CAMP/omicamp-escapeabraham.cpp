#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        if((n * n) - k == 1 || k > (n * n)){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            int actual = n * n;
            vector<vector<char>> maze(n, vector<char>(n, 'D'));
            maze[0][0] = 'R';
            maze[0][1] = 'L';
            actual -= 2;
            for(int i = 2; i < n; ++i){
                if(actual > k){
                    actual--;
                    maze[0][i] = 'L';
                }
            }            
            for(int i = 1; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(actual > k){
                        actual--;
                        maze[i][j] = 'U';
                    }
                }
            }
            if(k == n * n){
                maze[0][0] = maze[0][1] = 'D';
            }
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    cout << maze[i][j];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}