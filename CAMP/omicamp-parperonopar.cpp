#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> odds;
        odds.insert('1');
        odds.insert('3');
        odds.insert('5');
        odds.insert('7');
        odds.insert('9');

        set<int> pt;
        for(int i = n - 1; i >= 0; --i){
            if(odds.find(s[i]) != odds.end()){
                pt.insert(i);
            }
        }
        if(pt.size() <= 1){
            cout << "-1\n";
        }else{
            int a, b;
            auto itr1 = pt.begin();
            a = *itr1;
            itr1++;
            b = *itr1;
            cout << (char)(s[a]) << (char)(s[b]) << "\n";
        }
    }
    return 0;
}