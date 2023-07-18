#include <bits/stdc++.h>

#define MAXN 21

using namespace std;

int n, m;
vector<vector<char>> a(MAXN, vector<char>(MAXN));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    int p = 0, q = 0;
    while(p < (n+1)/2 && q < (m+1)/2){
        for(int i = q; i < m-q; ++i){
            cout << a[p][i];
        }
        for(int i = p+1; i < n-p; ++i){
            cout << a[i][m-1-q];
        }
        if(p != n-1-p){
            for(int i = m-q-2; i >= q; --i){
                cout << a[n-p-1][i];
            }
        }
        if(q != m-1-q){
            for(int i = n-p-2; i >= p+1; --i){
                cout << a[i][q];
            }
        }
        p++;+q++;
    }
    return 0;
}