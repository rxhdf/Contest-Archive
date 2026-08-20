#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int j = 0; j < m; ++j){
        cin >> b[j];
    }
    long long j = 0, i = 0, ans = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            ++i;
        }
        else if(a[i] > b[j]){
            ++j;
        }else{
            long long times1 = 0, times2 = 0;
            int vala = a[i];
            while(i < n && a[i] == vala){
                ++i;
                times1++;
            }
            int valb = b[j];
            while(j < m && b[j] == valb){
                ++j;
                times2++;
            }
            ans += times1 * times2;
        }
    }
    cout << ans << "\n";
    return 0;
}
