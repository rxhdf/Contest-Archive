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
    for(auto &e: a){
        cin >> e;
    }
    int final = n, mid = 0;
    while(!validate(a, mid, final)){
        mid += ((final - mid) / 2);
    }
    cout << final - mid << "\n";
    return 0;
}