#include <bits/stdc++.h>

#define MAXN (int)1e5+2

using namespace std;

int n;
int a[MAXN];
long long int cnt = 0, p = 0, im = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i]&1){
            //Impar
            cnt += p;
            ++im;
        }else {
            //Par
            cnt += im;
            ++p;
        }
    }
    cout << cnt << "\n";
    return 0;
}