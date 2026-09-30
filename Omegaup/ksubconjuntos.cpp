#include <bits/stdc++.h>
using namespace std;

int n, k;
string subset, s;
multiset<string> a;
void generatesubsets(int idx){
    if((int)subset.size() == k){
        a.insert(subset);
        return;
    }
    if(idx == n)return;
    generatesubsets(idx + 1);
    subset.push_back(s[idx]);
    generatesubsets(idx + 1);
    subset.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    cin >> s;
    generatesubsets(0);
    for(auto e: a)cout << e << "\n";
    return 0;
}