#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {0, 0, 1, - 1};
vector<int> dy = {-1, 1, 0, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matriz(n, vector<int>(m, 0));
        bool ok = true;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int nearby = 0;
                cin >> matriz[i][j];
                if(i > 0)nearby++;
                if(i < n - 1)nearby++;
                if(j > 0)nearby++;
                if(j < m - 1)nearby++;
                if(matriz[i][j] > nearby){
                    ok = false;
                }
                matriz[i][j] = nearby;
            }
        }
        if(!ok){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    cout << matriz[i][j] << " ";
                }
                cout << "\n";
            }
        }

        

    }

    return 0;
}