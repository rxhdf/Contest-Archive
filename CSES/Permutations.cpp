#include <bits/stdc++.h>
 
#define debugsl(x) std::cout << #x << " = " << x << ", "
#define debug(x) debugsl(x) << "\n";
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    if(n == 2 || n == 3){
        cout << "NO SOLUTION\n";
        return 0;
    }
    if(n&1){
        for(int i = n-1; i > 0; i-=2)
            cout << i << " ";
        for(int i = n; i > 0; i -=2)
            cout << i << " ";
    }else {
        for(int i = 2; i <= n; i+=2)
            cout << i << " ";
        for(int i = 1; i < n; i +=2)
            cout << i << " ";
    }
    return 0;
}