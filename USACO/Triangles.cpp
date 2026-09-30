#include <bits/stdc++.h>
#include <iomanip>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("triangles");
    ll n;
    cin >> n;
    vector<pair<double, double>> fences(n);
    for(int i = 0; i < n; ++i){
        cin >> fences[i].first >> fences[i].second;
    }
    double nax = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                if(i == j || i == k || j == k)continue;
                pair<double, double> v1 = fences[i], v2 = fences[j], v3 = fences[k];
                double area = (((v1.first * abs(v2.second - v3.second)) + (v2.first * abs(v3.second - v1.second)) + (v3.first * abs(v1.second - v2.second))) / 2);
                //cout << v1.first << " " << v1.second << " - " << v2.first << " " << v2.second << " - " << v3.first << " " << v3.second << "\n"; 
                //cout << area << "\n";
                nax = max(area, nax);
            }
        }
    }
    cout << setprecision(10) << nax * 2 << "\n";
    return 0;
}