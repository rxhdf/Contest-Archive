#include <bits/stdc++.h>

using namespace std;

struct human{
    int age, birth, death;
    friend bool operator<(const human& a, const human&b){
        return a.birth < b.birth;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    map<int, int> person;
    vector<human> humans;
    vector<int> querys;
    for(int i = 0; i < n; ++i){
        int l, r;
        cin >> l >> r;
        person[l] = r;
        humans.push_back({(r - l), l, r});
    }
    sort(humans.begin(), humans.end());

    for(int i = 0; i < q; ++i){
        int year;
        cin >> year;
        querys.push_back(year);
    }
    sort(querys.begin(), querys.end());
    int j = 0;
    for(int i = 0; i < querys.size(); ++i){
        while(humans[j].birth <= querys[i]){
            ++j;           
        }
    }

    for(auto e: humans)cout << e.birth << ' ' << e.death << "\n";
    return 0;
}