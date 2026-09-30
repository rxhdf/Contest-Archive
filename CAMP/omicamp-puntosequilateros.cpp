#include <bits/stdc++.h>

using namespace std;

struct Point{
    int a, b;
    friend bool operator<(Point &A, Point &B){
        return A.a < B.a;
    };
};

void solve(){
    int n;
    cin >> n;
    int res = ceil(sqrt(n));
    vector<Point> points(n);
    map<int, vector<Point>> horizontales;
    map<int, vector<Point>> sixty;//60
    map<int, vector<Point>> Twenty;//120

    for(int i = 0; i < n; ++i){
        cin >> points[i].a >> points[i].b;
        horizontales[points[i].b].push_back(points[i]);
        sixty[points[i].a].push_back(points[i]);
        Twenty[points[i].a - points[i].b].push_back(points[i]);
    }
    
    for(auto e: horizontales){
        if(e.second.size() >= res){
            for(int i = 0; i < res; ++i){
                cout << e.second[i].a << " " << e.second[i].b << "\n";
            }
            return;
        }
    }
    for(auto e: sixty){
        if(e.second.size() >= res){
            for(int i = 0; i < res; ++i){
                cout << e.second[i].a << " " << e.second[i].b << "\n";
            }
            return;
        }
    }
    for(auto e: Twenty){
        if(e.second.size() >= res){
            for(int i = 0; i < res; ++i){
                cout << e.second[i].a << " " << e.second[i].b << "\n";
            }
            return;
        }
    }
    vector<Point> ans;
    set<int>aused;
    for(auto e: horizontales){
        sort(e.second.begin(), e.second.end());
        for(int i = 0; i < e.second.size(); ++i){
        if(aused.find(e.second[i].a) != aused.end()){
            aused.insert(e.second[i].a);
            ans.push_back(e.second[i]);
        }
        }
        if(ans.size() == res)break;
    }
    for(auto e: ans){
        cout << e.a << " " << e.b << "\n";
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