#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &e: a)cin >> e;
    long long j = 0, segment_sum = 0, shortest = INT32_MAX;
    for(int i = 0; i < n; ++i){
        segment_sum += a[i];// add()
        while(segment_sum - a[j] >= k){//NO good()
            segment_sum -= a[j];//remove()
            j++;
        }
        if(segment_sum >= k)shortest = min(shortest, i - j + 1);
    }
    if(shortest == INT32_MAX)cout << "-1\n";
    else cout << shortest << "\n";
    return 0;
}