#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int seg;
    cin >> seg;
    if(seg >= 86400){
        int d = seg / 86400;
        cout << d << " dia" << (d == 1 ? "" : "s") << "\n";
    }else if(seg >= 3600){
        int h = seg / 3600;
        cout << h << " hora" << (h == 1 ? "" : "s") << "\n";
    }else if(seg >= 60){
        int m = seg / 60;
        cout << m << " minuto" << (m == 1 ? "" : "s") << "\n";
    }else{
        cout << seg << " segundo" << (seg == 1 ? "" : "s") << "\n";
    }
    return 0;
}
