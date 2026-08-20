#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); 
    //freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("");
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    vector<int> usb, ps;
    for(int i = 0; i < n; ++i){
        int cost;
        string type;
        cin >> cost >> type;
        if(type == "USB"){
            usb.push_back(cost);
        }else{
            ps.push_back(cost);
        }
    }

    sort(usb.begin(), usb.end());
    sort(ps.begin(), ps.end());

    long long stisfied = 0, cost = 0, l, r;
    for(int i = 0; i < usb.size(); ++i){
        l = i;
        if(a <= 0)break;
        stisfied++;
        cost += usb[i];
        usb[i] = INT32_MAX;
        a--;
    }
    for(int i = 0; i < ps.size(); ++i){
        r = i;
        if(b <= 0)break;
        stisfied++;
        cost += ps[i];
        ps[i] = INT32_MAX;
        b--;
    }
    vector<int> remainings;
    for(int i = 0; i < usb.size(); ++i){
        if(usb[i] != INT32_MAX)remainings.push_back(usb[i]);
    }
    for(int i = 0; i < ps.size(); ++i){
        if(ps[i] != INT32_MAX)remainings.push_back(ps[i]);
    }
    sort(remainings.begin(), remainings.end());
    for(auto e: remainings){
        if(c == 0)break;
        stisfied++;
        cost += e;
        --c;
    }
    cout << stisfied << " " << cost << "\n";
    return 0;
}