#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int N;
        cin >> N;
        string s;
        s += "1";
        cin >> s;
        bool ok = true;
        for(int k = 2; k <= N; ++k){
            int sz = s.size() / k;
            bool ok = true;
            string aux = "", aux2 = "";
            for(int i = 0; i < N; i+=sz){
                aux = s.substr(i, sz);
                aux2 = s.substr(i + sz, sz);
                if(aux[0] == aux2[aux2.length()-1]){
                    ok = false;
                    break;
                }
                cout << aux << " " << aux2 << "<-\n";
            }
            
        }
        if(ok == true){
            cout << "YES\n";
            break;
        }else{
            cout << "NO\n";
            break;
        }
    }

    return 0;
}