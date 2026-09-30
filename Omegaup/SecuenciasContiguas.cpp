#include <bits/stdc++.h>
using namespace std;

vector<int> a;
unordered_map<int, int> positions;

bool validate(int l, int r){
    for(int i = l; i <= r; ++i){
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    a.resize(n + 1, 0);
    
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        positions[a[i]] = i;
    }
    //size, i, j
    set<tuple<int, int, int>> subsequences;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            auto ok = validate(i, j);
        }
    }
    return 0;
}