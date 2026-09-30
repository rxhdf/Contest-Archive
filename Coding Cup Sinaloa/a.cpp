#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct query{
    int xi, yi, xe, ye, xsi, ysi, xse, yse; 
};

query get_coordinates(string s){
    query coordinates = {0, 0, 0, 0, 0, 0, 0, 0};
    for (char &ch : s) if (ch == ',') ch = ' ';
    stringstream ss(s);
    ss >> coordinates.xi >> coordinates.yi >> coordinates.xe >> coordinates.ye >> coordinates.xsi >> coordinates.ysi >> coordinates.xse >> coordinates.yse;
    return coordinates;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, q;
    cin >> r >> c;
    vector<vector<ll>> matrix(r + 2, vector<ll>(c + 2, 0));
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            cin >> matrix[i][j];
        }
    }
    vector<vector<ll>> pref(r + 2, vector<ll>(c + 2, 0));
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            pref[i][j] = matrix[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    auto rectSum = [&](int x1, int y1, int x2, int y2)->long long {
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
    };

    cin >> q;
    while(q--){
        string s;
        getline(cin >> ws, s);
        auto e = get_coordinates(s);
        ll A = rectSum(e.xi, e.yi, e.xe, e.ye);
        ll B = rectSum(e.xsi, e.ysi, e.xse, e.yse);
        if (A > B) cout << "1\n";
        else if (B > A) cout << "2\n";
        else cout << "0\n";
    } 
    return 0;
}




/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1,1 2,2 3,3 4,4
3,1 4,2 1,3 2,4
2,3 2,4 4,3 4,3
*/