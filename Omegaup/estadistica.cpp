#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> S;
set<int> V;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    S.resize(N + 2, 0);
    for (int i = 1; i <= N; ++i) cin >> S[i];
    for(int i = 1; i <= M; ++i){
        int v;
        cin >> v;
        V.insert(v);
    }
    

    int total_diff = 0;
    for (int i = 1; i < N; ++i) total_diff += abs(S[i] - S[i + 1]);

    cout << total_diff << '\n';
    for (int i = 1; i <= N; ++i) cout << S[i] << " ";
    cout << '\n';

    return 0;
}
