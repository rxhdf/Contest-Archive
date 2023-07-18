#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int n, m, k, a, b, minimo, maximo;
queue<int> q;
int inf[MAX] = {0};
vector<vector<int>> adj_list(MAX);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        inf[a] = 1;
    }
    minimo = maximo = k;

    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj_list[a].push_back(b);
        if(inf[a] == 1 && inf[b] == 0){
            minimo ++; 
            inf[b] = 2;
            q.push(b);
        }   
    } 
    while(!q.empty()){
        maximo++;
        for(auto e : adj_list[q.front()]){
            if(inf[e] == 0){
                inf[e] = 2;
                q.push(e);
            }
        }
        q.pop();
    }
    cout << minimo << " " << maximo << "\n";

    return 0;
}