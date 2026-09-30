#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#define ll unsigned long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool validate(vector<int> thanos, int mid, int end){
    for(int i = mid; i < end - 1; ++i){
        if(thanos[i] > thanos[i + 1]){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &e: a){
        cin >> e;
    }
    for(auto &e: b){
        cin >> e;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll P1 = 0, P2  = 0;
    for(auto e: a){
        auto it1 = lower_bound(b.begin(), b.end(), e);
        auto it2 = upper_bound(b.begin(), b.end(), e);
        P1 += it1 - b.begin();
        P2 += b.end() - it2;
    }
    if(P1 > P2){
        cout << "Avengers\n" << (P1 - P2)  << "\n";
    }else{
        cout << "Thanos\n" << (P2 - P1 + 1) << "\n";
    }
    return 0;

}