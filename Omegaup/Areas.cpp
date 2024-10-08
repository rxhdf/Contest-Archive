#include <bits/stdc++.h>
#include <ios>
#define MAX 300

using namespace std;

struct Query{
    int x, y, plan, time;
    friend bool operator<(const Query& A, const Query& B){
        return A.time > B.time;
    };
};

int N, M, K, L, Q;
int area[MAX][MAX], prefix[MAX][MAX];
set<Query> QS;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K >> L;
    memset(prefix, 0, sizeof(prefix));
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> area[i][j];
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i - 1][j - 1] + area[i][j]; 
        }
    }
    cin >> Q;
    for(int i = 1; i <= Q; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Query nxt = {a, b, c, d};
        QS.insert(nxt);
    }
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= M; ++j){
            cout << prefix[i][j] << " ";
        }
        cout << "\n";
    }
    for(auto actual: QS){
        prefix[actual.x][actual.y] += actual.plan;
    }   
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= M; ++j){
            cout << prefix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}