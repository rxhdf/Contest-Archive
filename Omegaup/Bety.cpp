#include <bits/stdc++.h>

using namespace std;

int N, M, K, X = 0, Y = 0;
bool A = false, B = false;

void ChangeY(vector<vector<int>> &MT, vector<vector<int>> &aux){
    if(A){
        int cnt = 1; 
        for(int i = Y + 1; i <= N; ++i){
            aux[cnt] = MT[i];
            ++cnt;
        }
        for(int i = Y; i >= 1; --i){
            aux[cnt] = MT[i];
            ++cnt;
        }
    }else{
        int cnt = 1;
        for(int i = M - Y + 1; i <= N; ++i){
            aux[cnt] = MT[i];
            ++cnt;
        }
        for(int i = M - Y; i >= 1; --i){
            aux[cnt] = MT[i];
            ++cnt;
        }   
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    vector<vector<int>> MT(N + 1, vector<int>(M + 1, 0));
    for(int i = 0; i < K; ++i){
        int a;
        cin >> a;
        if(a == 1){
            Y--;
        }else if(a == 2){
            Y++;
        }else if(a == 3){
            X--;
        }else if( a == 4){
            X++;
        }
       
    } 
    if(Y <= 0){
        B = false;
        Y = abs(Y);
    }else{
        B = true;
    }
       
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> MT[i][j];
        }
    }
    if(X <= 0){
        A = false;
        X = abs(X);
    }else{
        A = true;
    }
    X %= N;
    Y %= M;
    cout << A << " " << B << "\n";
    cout << X << " " << Y << "\n";
    vector<vector<int>> aux(N+3, vector<int>(M+3));
    //change in Y
    ChangeY(MT, aux);
    
    //change
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cout << aux[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;   
}