#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e: a){
        cin >> e;
    }
    sort(a.begin(), a.end());
    multiset<int> towers;
    for(auto e: a){
        auto it = towers.upper_bound(e);
        if(it == towers.begin()){
            towers.insert(1);
        }else{
            --it;
            int nH = *it;
            towers.erase(it);
            towers.insert(nH + 1);
        }
    }
    cout << towers.size() << "\n";
    return 0;
}
