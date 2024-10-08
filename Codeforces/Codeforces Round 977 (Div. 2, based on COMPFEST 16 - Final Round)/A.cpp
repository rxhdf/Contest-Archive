#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve(){
    int N;
    cin >> N;
    vector<int> A;
    for(int i = 1; i <= N; ++i){
        int x;
        cin >> x;
        A.push_back(x);
    }
    while(A.size() > 1){
        auto a = max_element(A.begin(),  A.end());
        int v = *a;
        A.erase(a);
        a = min_element(A.begin(),  A.end());
        int g = *a;
        cout << v << " " << g << "\n";
        A.erase(a);
        A.push_back(floor((g + v) / 2));
    }
    cout << A[0] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--)
        solve();


    return 0;
}