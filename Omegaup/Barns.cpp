#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int M, C, S, g = 0, len = 0;
    cin >> M >> C >> S;
    vector<int> cows(S), gaps;
    for(int i = 0; i < S; ++i){
        cin >> cows[i];
    }
    for(int i = 1; i < S; ++i){
        int gap = cows[i] - cows[i - 1] - 1;
        if(gap)gaps.push_back(gap);
    }
    sort(gaps.rbegin(), gaps.rend());
    len = cows[S - 1] - cows[0] + 1;
    for(int i = 0; i < min(M - 1, (int)gaps.size()); ++i){
        g += gaps[i];
    }
    cout << len - g << "\n";
    return 0;
}