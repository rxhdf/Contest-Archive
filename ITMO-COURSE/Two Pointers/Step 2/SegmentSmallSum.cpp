#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &e: a)cin >> e;
    long long j = 0, segment_sum = 0, longest = 0;
    for(int i = 0; i < n; ++i){
        segment_sum += a[i];// add()
        while(segment_sum > k){//NO good()
            segment_sum -= a[j];//remove()
            j++;
        }
        longest = max(longest, i - j + 1);
    }
    cout << longest << "\n";
    return 0;
}