#include <bits/stdc++.h>

#define MAXN 105

using namespace std;

int n, m;
int a[MAXN][MAXN];
vector<int> f, c;

void mvVertical(){
    for(int i = 0; i < n; ++i){
        if(a[i][m] < 0){
            f.push_back(i+1);
            for(int j = 0; j < m; ++j){
                a[i][j] *= -1;
            }
        }
    }
    for(int i = 0; i < m; ++i){
        a[n][i] = 0;
        for(int j = 0; j < n; ++j){
            a[n][i] += a[j][i];
        }
    }
}
void mvHorizontal(){
    for(int i = 0; i < m; ++i){
        if(a[n][i] < 0){
            c.push_back(i+1);
            for(int j = 0; j < n; ++j){
                a[j][i] *= -1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        a[i][m] = 0;
        for(int j = 0; j < m; ++j){
            a[i][m] += a[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
            a[i][m] += a[i][j];
        }
    }
    for(int i = 0; i < 9; ++i){
        mvVertical();
        mvHorizontal();
    }
    cout << f.size() << " ";
    for(int i = 0; i < f.size(); ++i){
        cout << f[i] << " ";
    }
    cout << "\n";
    cout << c.size() << " ";
    for(int i = 0; i < c.size(); ++i){
        cout << c[i] << " ";
    }
    cout << "\n";
    
    return 0;
}