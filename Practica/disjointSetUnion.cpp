#include <bits/stdc++.h>

using namespace std;

vector<int> parent, sizeq, querys;
int maxSize = 0, counter = 0;

void make_set(int v){
    parent[v] = v;
    sizeq[v] = 1;
}
int find_set(int v){
    if(parent[v] == v){
        return v;
    }
    //Path Compression
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sizeq[a] < sizeq[b]){
            swap(a, b);
        }
        parent[b] = a;
        sizeq[a] += sizeq[b];
        maxSize = max(sizeq[a], maxSize);
        counter--;
    }
}


void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("closing");
    int n, m;
    cin >> n >> m;
    set<int> quitados;
    parent.resize(n + 1, 0);
    sizeq.resize(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    for(int i = 1; i <= n; ++i){
        quitados.insert(i);
        make_set(i);
    }
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int aux = n;
    while(aux--){
        int x;
        cin >> x;
        querys.push_back(x);
    }
    vector<bool> ans(n + 1, false);
    for(int i = n - 2; i >= -1; --i){
        counter++;
        quitados.erase(quitados.find(querys[i + 1]));
        for(auto e: graph[querys[i + 1]]){
            if(quitados.find(e) != quitados.end())continue;
            union_sets(querys[i + 1], e);
        }
        //Cantidad de componentes
        if(counter <= 1){
            ans[i + 1] = 1;
        }else{
            ans[i + 1] = 0;
        }
    }
    for(int i = 0; i < n; ++i){
        if(ans[i])cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/*
4 3
1 2
2 3
3 4
3
4
1
2
*/