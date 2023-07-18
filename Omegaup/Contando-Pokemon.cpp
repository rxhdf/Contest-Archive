#include <bits/stdc++.h>

#define MAXN 105

using namespace std;

int n, m;

vector<int> movs(105), eps(105);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> movs[i];
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> eps[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cnt = 0;
        for(int j = 0; j < m; ++j){
            if(eps[j] <= movs[i])cnt++;
        }
        cout << cnt << " ";
    }
    return 0;
}