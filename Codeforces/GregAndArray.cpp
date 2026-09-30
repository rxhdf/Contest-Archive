#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> diff(n + 2), a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<tuple<int, int, int>> ops(m);
    for(int j = 0; j < m; ++j){ 
        cin >> ops[0] >> ops[1] >> ops[2];
    }

    for(int i = 0; i < k; ++i){
        int x, y;
        cin >> x >> y;
    }

    return 0;
}