#include <bits/stdc++.h>

using namespace std;


int n;
vector<vector<int>> mat;

bool check(vector<int> &c){
    bool ok = true;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)continue;
            if(mat[i][j] != abs(c[i] - c[j])){
                return ok = false;
            }
        }
    }
    return ok;
}

void solve(){
    cin >> n;
    mat.resize(n + 2);
    for(int i = 1; i <= n; ++i){
        mat[i].resize(n + 1);
    }
    for(int i = 0; i < (n * (n - 1)) / 2; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = c;
        mat[b][a] = c;
    }
    //supon que el nodo i siempre inicia con el valor de 0
    bool isValid = true;
    for(int i = 1; i <= n; ++i){
        vector<int> aux(n + 1);
        aux[i] = 0; 
        for(int j = 1; j <= n; ++j){
            if(i == j)continue;
            aux[j] = mat[i][j];
        }
        isValid = check(aux);
        if(isValid){
            for(int i = 1; i <= n; ++i){
                cout << aux[i] << " ";
            }
            cout << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}