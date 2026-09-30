#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a(n);
        string aux = "";
        for(auto &e: a){
            cin >> e;
            aux += e + '0';
        }   
        //ya es palindromo
        auto palindrome = [&](string s){
            string aux = s;
            reverse(aux.begin(), aux.end());
            return (aux == s);
        };
        if(palindrome(aux)){
            cout << "YES\n";
        }else{
            int l = 0, r = n - 1;
            while(aux[l] == aux[r] && l <= r){
                ++l;
                --r;
            }
            //quitando el 0 o el n-1;
            string qP = "";
            for(int i = 0; i < aux.length(); ++i){
                if(aux[i] != aux[l])qP += aux[i];
            }
            if(palindrome(qP)){
                cout << "YES\n";
                continue;
            }
            string qU = "";
            for(int i = 0; i < aux.length(); ++i){
                if(aux[i] != aux[r])qU += aux[i];
            }

            if(palindrome(qU) ){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }

        }
    }
    return 0;   
}

