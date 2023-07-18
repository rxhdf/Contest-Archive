#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define snd second
#define fst first

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b){
    if (a.second < b.second){
        return true;
    }
    return false;
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<pair<int, int> > A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i].fst >> A[i].snd;
    }
    sort(begin(A), end(A), comp);
    multiset<int> v;
    for(int i = 0; i < K; ++i)v.insert(0);
    int answer = 0;    
    for(int i = 0; i < N; ++i){
        auto it = v.upper_bound(A[i].fst);
        if(it == begin(v))continue;
        v.erase(--it);
        v.insert(A[i].snd);
        ++answer;
    }
    cout << answer << "\n";
}