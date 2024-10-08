#include <bits/stdc++.h>
#include <ios>
#define MAX 30002
using namespace std;

int N, V;
vector<int> VS(MAX), A(MAX);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> V;
    A.resize(N + 1);
    iota(A.begin() + 1, A.end(), 1);
    for(int i = 1; i <= V; ++i){
        int v;
        cin >> v;
        for(int j = v, h = N; j <= h; ++j, --h){             
            swap(A[j], A[h]);
        }        
    }
    for(int i = 1; i <= N; ++i)cout << A[i] << " ";
    cout << "\n";
    return 0;
}