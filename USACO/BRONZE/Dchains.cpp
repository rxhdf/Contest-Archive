#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    //freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("");
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e: a){
        cin >> e;
    }
    int answer = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            double average = 0;
            map<double, int> flowers;
            for(int k = i; k <= j; ++k){
                average += a[k];
                flowers[a[k]]++;
            }
            average /= (ll)(j - i + 1);
            //cout << flowers[average] << "===" << i << " " << j << "\n";
            answer += (flowers[average] ? 1 : 0);
        }
    }
    cout << answer << "\n";
    return 0;
}