#include <bits/stdc++.h>

#define INF INT32_MAX
#define MAXN 10002

using namespace std;

int N, M, F, Fotos = 0;
int Matriz[MAXN][MAXN];

void floyd(){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < M; ++i){ 
        int a, b;
        cin >> a >> b;
        Matriz[a][b] = 1;
        Matriz[b][a] = 1;
    }
    return 0;
}