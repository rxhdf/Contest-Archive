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
        multiset<int> odd, even;
        int start;
        cin >> start;
        for(int i = 1; i < n; ++i){
            int x;
            cin >> x;
            if(x & 1){
                odd.insert(x);
            }else{
                even.insert(x);
            }
        }
        vector<int> ans(n, 0);
        ans[0] = start;
        for(int i = 1; i < n; ++i){
            if(ans[i - 1] & 1){
                if(!odd.empty()){
                    auto odd_actual = odd.begin();
                    ans[i] = *odd_actual;
                    odd.erase(odd_actual);
                }
                else if(!even.empty()){
                    auto even_actual = even.begin();
                    ans[i] = *even_actual;
                    even.erase(even_actual);
                }
            }else{
                if(!even.empty()){
                    auto even_actual = even.begin();
                    ans[i] = *even_actual;
                    even.erase(even_actual);
                }
                else if(!odd.empty()){
                    auto odd_actual = odd.begin();
                    ans[i] = *odd_actual;
                    odd.erase(odd_actual);
                }
            }   
        }
        for(auto e: ans){
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}