#include <bits/stdc++.h>
using namespace std;

struct PairHash{
    size_t operator()(const pair<int,int>& p) const noexcept {
        return (static_cast<size_t>(p.first) << 32) ^ static_cast<size_t>(p.second);
    }
};

int n, f, c;
unordered_map<pair<int, int>, char, PairHash> types;
unordered_map<pair<int, int>, pair<int, int>, PairHash> nextN, nextS, nextE, nextO;

auto change(char orientation, char reflectionType){
    char newDirection;
    if(orientation == 'N'){
        if(reflectionType == '/') newDirection = 'E';
        else newDirection = 'O';
    }
    else if(orientation == 'S'){
        if(reflectionType == '/') newDirection = 'O';
        else newDirection = 'E';
    }
    else if(orientation == 'E'){
        if(reflectionType == '/') newDirection = 'N';
        else newDirection = 'S';
    }
    else if(orientation == 'O'){
        if(reflectionType == '/') newDirection = 'S';
        else newDirection = 'N';
    }
    return newDirection;
}

int validate(int x, int y, char orientation){
    set<tuple<int, int, char>> visited;
    int mirrors = 0;
    if(types.count({x,y})){
        orientation = change(orientation, types[{x,y}]);
        auto state0 = make_tuple(x, y, orientation);
        if(visited.find(state0) != visited.end()) return -1;
        visited.insert(state0);
        mirrors++;
    }

    while(true){
        pair<int, int> nxt;
        bool hasNxt = false;
        if(orientation == 'N' && nextN.count({x, y})){
            nxt = nextN[{x, y}]; hasNxt = true;
        }
        else if(orientation == 'S' && nextS.count({x, y})){
            nxt = nextS[{x, y}]; hasNxt = true;
        }
        else if(orientation == 'E' && nextE.count({x, y})){
            nxt = nextE[{x, y}]; hasNxt = true;
        }
        else if(orientation == 'O' && nextO.count({x, y})){
            nxt = nextO[{x, y}]; hasNxt = true;
        }
        if(!hasNxt) return mirrors;

        x = nxt.first; y = nxt.second; 
        orientation = change(orientation, types[{x, y}]);
        auto state = make_tuple(x, y, orientation);
        if(visited.find(state) != visited.end()) return -1;
        visited.insert(state);
        mirrors++;
    }
    return mirrors;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> f >> c;
    vector<vector<int>> mirror_rows(f + 1), mirror_columns(c + 1); 

    for(int i = 1; i <= n; ++i){
        char type; int x, y;
        cin >> type >> x >> y;
        mirror_rows[x].push_back(y);
        mirror_columns[y].push_back(x);
        types[{x, y}] = type;
    }

    for(int i = 0; i < mirror_columns.size(); ++i){
        auto &column = mirror_columns[i];
        sort(column.begin(), column.end());
        for(int j = 0; j < column.size(); ++j){
            int x = column[j];
            if(j > 0) nextS[{x, i}] = {column[j - 1], i};
            if(j + 1 < column.size()) nextN[{x, i}] = {column[j + 1], i};
        }
    }   

    for(int i = 0; i < mirror_rows.size(); ++i){
        auto &row = mirror_rows[i];
        sort(row.begin(), row.end());
        for(int j = 0; j < row.size(); ++j){
            int y = row[j];
            if(j > 0) nextO[{i, y}] = {i, row[j - 1]};
            if(j + 1 < row.size()) nextE[{i, y}] = {i, row[j + 1]};
        }
    }

    int e; 
    cin >> e;
    while(e--){
        int answer = 0;
        char orientation; int x, y;
        cin >> orientation >> x >> y;
        if(orientation == 'N'){
            auto &col = mirror_columns[y];
            auto it = upper_bound(col.begin(), col.end(), x);
            if(it != col.end()) answer = validate(*it, y, orientation);
        }
        else if(orientation == 'S'){
            auto &col = mirror_columns[y];
            auto it = lower_bound(col.begin(), col.end(), x);
            if(it != col.begin()){ --it; answer = validate(*it, y, orientation); }
        }
        else if(orientation == 'E'){
            auto &row = mirror_rows[x];
            auto it = upper_bound(row.begin(), row.end(), y);
            if(it != row.end()) answer = validate(x, *it, orientation);
        }
        else if(orientation == 'O'){
            auto &row = mirror_rows[x];
            auto it = lower_bound(row.begin(), row.end(), y);
            if(it != row.begin()){ --it; answer = validate(x, *it, orientation); }
        }

        cout << answer << "\n";
    }

    return 0;
}
