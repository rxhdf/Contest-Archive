#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, s; cin >> n >> s;
    vector <int> a(n);
    for (auto &e : a) cin >> e;

    long long j = 0;
    long long currentSum = 0, minSegment = LONG_LONG_MAX;
    for (long long i = 0; i < n; i++){
        currentSum += a[i];
        while (currentSum - a[j] >= s){
            currentSum -= a[j];
            j++;
        }
        if(currentSum >= s)minSegment = min(minSegment, (i - j + 1));
    }
    cout << (minSegment != LONG_LONG_MAX ? minSegment : -1) << '\n';
}