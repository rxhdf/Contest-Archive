#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n <= 6){
        set<pair<int, int>> uno, dos;
        for(int i = 0; i < (n * (n - 1)) / 2; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            if(c){
                dos.insert({a, b});
            }else{
                uno.insert({a, b});
            }
        }
        tuple<int, int, int> ans = {-1, -1, -1};
        for(auto e: uno){
            for(auto h: uno){
                if(e.first == h.first){
                    if(uno.find({e.second, h.second}) != uno.end() || uno.find({h.second, e.second}) != uno.end()){
                        ans = {e.first, e.second, h.second};
                    } 
                }
            }
        }
        for(auto e: dos){
            for(auto h: dos){
                if(e.first == h.first && e != h){
                    //cout << e.first << " " << e.second << " " << h.first << " " << h.second << "Hola\n";
                    if(dos.find({e.second, h.second}) != dos.end() || dos.find({h.second, e.second}) != dos.end()){
                        ans = {e.first, e.second, h.second};
                    } 
                }
            }
        }
        if(get<0>(ans) == -1){
            cout << "-1\n";
        }else{
            cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << "\n";
        }
    }else{
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, -1));
        for(int i = 0; i < (n * (n - 1))/ 2; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] = c;
            adj[b][a] = c;
        }
        for(int i = 1; i <= n; ++i){
            vector<int> colorUno;
            vector<int> colorDos;
            for(int j = i + 1; j <= n; ++j){
                if(adj[i][j] == -1)continue;
                else{
                    if(adj[i][j] == 0){
                        colorUno.push_back(j);
                    }else{
                        colorDos.push_back(j);
                    }
                }
            }
            if(colorUno.size() >= 3){
                int a = colorUno[0], b = colorUno[1], c = colorUno[2];
                if(adj[a][b] == 0){
                    cout << i << " " << a << " " << b << "\n";
                }
                else if(adj[a][c] == 0){
                    cout << i << " " << a << " " << c << "\n";
                }
                else if(adj[b][c] == 0){
                    cout << i << " " << b << " " << c << "\n";
                }else{
                    cout << a << " " << b << " " << c << "\n";
                }
                return;
            }
            else if(colorDos.size() >= 3){
                int a = colorDos[0], b = colorDos[1], c = colorDos[2];
                if(adj[a][b] == 1){
                    cout << i << " " << a << " " << b << "\n";
                }
                else if(adj[a][c] == 1){
                    cout << i << " " << a << " " << c << "\n";
                }
                else if(adj[b][c] == 1){
                    cout << i << " " << b << " " << c << "\n";
                }else{
                    cout << a << " " << b << " " << c << "\n";
                }
                return;
            }
        }
        cout << "-1\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }

    return 0;
}