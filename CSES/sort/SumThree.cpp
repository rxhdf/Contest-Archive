    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; ++i){
            int l = 0, r = n - 1;
            while(l < r){
                int target = k - a[i].first;
                if(l != i && r != i && a[l].first + a[r].first == target){
                    cout << a[l].second << " " << a[i].second << " " << a[r].second << "\n";
                    return 0;
                }
                if(a[l].first + a[r].first >= target)r--;
                else l++;
            }   
        }
        cout << "IMPOSSIBLE\n";
        return 0;
    }