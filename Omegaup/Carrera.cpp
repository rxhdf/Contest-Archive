#include <bits/stdc++.h>
using namespace std;

struct runner{
    int id;
    string name;
    float time;
    int category;
};

bool cmp(runner a, runner b){
    return a.time < b.time;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<runner> a, b;
    for(int i = 0; i < n; ++i){
        int category, id;
        string name;
        float time;
        cin >> id;      
        cin.ignore();     
        getline(cin, name); 
        cin >> time >> category;
        if(category == 1){
            a.push_back({id, name, time, category});
        }else{
            b.push_back({id, name, time, category});
        }   
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    if(a.size()){
        for (int i = 0; i < min(3, (int)a.size()); ++i) {
            cout << a[i].id << " " << a[i].name << "\n";
        }
    }
    
    if(b.size()){
       for (int i = 0; i < min(3, (int)b.size()); ++i) {
            cout << b[i].id << " " << b[i].name << "\n";
        } 
    }
    return 0;
}