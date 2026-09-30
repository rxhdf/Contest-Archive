#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> min_heap; //To store de positive nombers in desending order
        multiset<ll> max_heap; //To maintain the negative numbers in ascending order 
        queue<int> zeros;
        for(int i = 0; i < n; ++i){
            ll x;
            cin >> x;
            if(x < 0)max_heap.insert(x);
            else if(x >= 1){
                min_heap.push(x);
            }else{
                zeros.push(x);
            }
        }
        vector<ll> a(n, 0);
        if(min_heap.empty()){
            cout << "-1\n";
            continue;
        }
        a[0] = min_heap.top();
        min_heap.pop();
        bool ok = true;
        for(int i = 1; i < n; ++i){
            auto minimo =  max_heap.lower_bound(-a[i - 1] + 1);
            if(!max_heap.empty() && minimo != max_heap.end()){
                a[i] = a[i - 1] + *minimo;
                max_heap.erase(minimo);
            }
            else if(!zeros.empty()){
                a[i] = a[i - 1];
                zeros.pop();
            }
            else if(!min_heap.empty()){
                a[i] = a[i - 1] + min_heap.top();
                min_heap.pop();
            }else{
                ok = false;
                break;
            }
        }
        if(ok){
            for(auto e: a){
                cout << e << " ";
            }
            cout << "\n";
        }else{
            cout << "-1\n";
        }
    }

    return 0;
}