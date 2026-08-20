#include <bits/stdc++.h>
using namespace std;

int main(){
    int R, C; cin >> R >> C;
    vector <vector <int>> m(R + 2, vector <int> (C + 2, 0));

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> m[i][j];

    vector <vector <int>> prefix(R + 1, vector <int> (C + 1));
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            prefix[i][j] = m[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    
    int q; 
    cin >> q;
    while(q--){
        int r1, c1; scanf("%d,%d", &r1, &c1);
        int r2, c2; scanf("%d,%d", &r2, &c2);

        int totalA = prefix[r2][c2] - prefix[r2][c1-1] - prefix[r1-1][c2] + prefix[r1-1][c1-1];

        scanf("%d,%d", &r1, &c1);
        scanf("%d,%d", &r2, &c2);

        int totalB = prefix[r2][c2] - prefix[r2][c1-1] - prefix[r1-1][c2] + prefix[r1-1][c1-1];

        if (totalA == totalB){
            cout << 0 << '\n';
            continue;
        }

        cout << ((totalA > totalB) ? 1 : 2) << '\n';
    }
}