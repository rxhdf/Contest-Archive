#include <bits/stdc++.h>
#include <utility>
#define MAX 1002
#define Matrix vector<vector<char>> 

using namespace std;

int N, M;
vector<int> f = {1, 0, 0, -1};
vector<int> c = {0, 1, -1, 0};
Matrix Garden(MAX, vector<char>(MAX, '#'));
Matrix GardenZ(MAX, vector<char>(MAX, '.'));
set<pair<int, int>> corners_free, corners_rock;
set<pair<pair<int, int>, pair<int, int>>> walls;

bool check_wall_x(int x, int y){
    int a = x, b = y;
    bool ok = true;
    while(ok && x >= 1){
        --x;
        if(corners_rock.find({x, y}) != corners_rock.end()){
            walls.insert(make_pair(make_pair(x, y), make_pair(a, b)));
        }
        if(GardenZ[x][y] == '.')ok = false;
    }
    x = a;
    while(ok && x <= N){
        ++x;
        if(corners_rock.find({x, y}) != corners_rock.end()){
            walls.insert(make_pair(make_pair(x, y), make_pair(a, b)));
        }
        if(GardenZ[x][y] == '.')ok = false;
    }
    return ok;
}


bool check_corner_rock(int x, int y){
    if(){

    }   
    else if(){

    } 
    else if(){
        
    } 
    else if(){
        
    } 
}

bool check_corner_point(int x, int y){
    if(Garden[x][y] == '.' && Garden[x + 1][y - 1] == '#' && Garden[x + 1][y] == '#' && Garden[x][y - 1] == '#'){
        return true;
    }
    else if(Garden[x][y] == '.' && Garden[x + 1][y + 1] == '#' && Garden[x + 1][y] == '#' && Garden[x][y + 1] == '#'){
        return true;
    }
    else if(Garden[x][y] == '.' && Garden[x - 1][y - 1] == '#' && Garden[x - 1][y] == '#' && Garden[x][y - 1] == '#'){
        return true;
    }
    else if(Garden[x][y] == '.' && Garden[x - 1][y + 1] == '#' && Garden[x - 1][y] == '#' && Garden[x][y + 1] == '#'){
        return true;
    }
    return false;
}

void validate(int x, int y){
    if(!corners_free.count({x, y})){
        bool corner = check_corner_point(x, y);
        if(corner)corners_free.insert(make_pair(x, y));
    }   
}

void validate2(int x, int y){
    if(!corners_rock.count({x, y})){
        bool corner = check_corner_rock(x, y);
        if(corner)corners_rock.insert(make_pair(x, y));
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> Garden[i][j];
            GardenZ[i][j] = Garden[i][j];
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(Garden[i][j] == '.')validate(i, j);
            //else if(Garden[i][j] == '#')validate2(i, j);
        }
    }
    
    cout << "b\n";
    for(auto e: corners_free){
        cout << e.first << e.second << "\n";
    }
    cout << "---\n";
    for(auto e: walls){
        cout << e.first.first << " " << e.first.second << "-" << e.second.first << " " << e.second.second << "\n";
    }
    return 0;
}