#include <bits/stdc++.h>

using namespace std;

struct Node{
    int pos, Dist;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int N, M, K;
        bool yes = false;
        cin >> N >> M >> K;
        string S;
        cin >> S;
        S = 'L' + S + 'L';
        N += 2;
        vector<int> distances(N, -1);
        queue<Node> Q;
        Q.push({0, 0});
        distances[0] = 0;
        while(!Q.empty()){
            Node nw = Q.front();
            Q.pop();
            if(nw.pos == N - 1){
                yes = true;
                break;
            }
            for(int i = 1; i <= M; ++i){
                int NP = nw.pos + i;
                if(NP >= N)break;
                if(S[NP] == 'C')continue;
                if(distances[NP] == -1){
                    distances[NP] = nw.Dist;
                    Q.push({NP, nw.Dist});
                }
            }
            if(nw.pos + 1 < N && S[nw.pos + 1] != 'C' && nw.Dist + 1 <= K){
                if(distances[nw.pos + 1] == -1||distances[nw.pos + 1] > nw.Dist + 1){
                    distances[nw.pos + 1] = nw.Dist + 1;
                    Q.push({nw.pos + 1, nw.Dist + 1});
                }
            }
        }
        if(!yes)cout << "No\n";
    }
    return 0;
}