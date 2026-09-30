#include <bits/stdc++.h>

using namespace std;

struct number{
    int index;
    bool infront = false, behind = false;
}; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n >> m;
    unordered_map<int, number> mp;
    mp[0] = {0, true, true};
    mp[n + 1] = {(n + 1), true, true};
    vector<int> a(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        mp[a[i]] = {i, false, false};
    }
    for(auto &e: mp){
        if(e.first == 1){
            e.second.behind = true;
            if(mp[e.first + 1].index > e.second.index){
                e.second.infront = true;
            }
        }   
        else if(e.first == n){
            e.second.infront = true;
            if(mp[e.first - 1].index < e.second.index){
                e.second.behind = true;
            }
        }else{
            if(mp[e.first + 1].index > e.second.index){
                e.second.infront = true;
            }
            if(mp[e.first - 1].index < e.second.index){
                e.second.behind = true;
            }
        }
    }
    int ans = 1;
    for(int i = 1; i < n; ++i){
        if(mp[i].index > mp[i + 1].index )ans++;
    }
    for(int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        swap(mp[a[x]].index, mp[a[y]].index);
        swap(a[x], a[y]);
        if(mp[a[x]].index < mp[a[x + 1]].index){
            if(!mp[a[x]].infront){
                ans--;
                mp[a[x]].infront = true;
            }
        }
        else if(mp[a[x]].index > mp[a[x + 1]].index){
                if(mp[a[x]].infront){
                    ans++;
                    mp[a[x]].infront = false;
                }
        }
        if(mp[a[x]].index > mp[a[x - 1]].index){
                if(!mp[a[x]].behind){
                    ans--;
                    mp[a[x]].behind = true;
                }
        }  
        else if(mp[a[x]].index < mp[a[x - 1]].index){
                if(mp[a[x]].behind){
                    ans++;
                    mp[a[x]].behind = false;
                }
        }
        //
        if(mp[a[y]].index < mp[a[y + 1]].index){
            if(!mp[a[y]].infront){
                ans--;
                mp[a[y]].infront = true;
            }
        }
        if(mp[a[y]].index > mp[a[x + 1]].index){
                if(mp[a[y]].infront){
                    ans++;
                    mp[a[y]].infront = false;
                }
        }
        if(mp[a[y]].index > mp[a[y - 1]].index){
                if(!mp[a[y]].behind){
                    ans--;
                    mp[a[y]].behind = true;
                }
        }  
        if(mp[a[y]].index < mp[a[y - 1]].index){
                if(mp[a[y]].behind){
                    ans++;
                    mp[a[y]].behind = false;
                }
        } 
        cout << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}