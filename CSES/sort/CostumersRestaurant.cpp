#include <bits/stdc++.h>

using namespace std;

struct CostumersRestaurant{
    int arrival;
    int departure;
    friend bool operator<(const CostumersRestaurant &a, const CostumersRestaurant &b) {
        return a.departure < b.departure;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<CostumersRestaurant> customers(N);
    for(auto &e: customers){
        cin >> e.arrival >> e.departure;
    }
    sort(customers.begin(), customers.end());
    int ans = 0;
    int range = 1;
    for(int i = 0; i < N - 1; ++i){
        if(customers[i].departure > customers[i + 1].arrival){
            range++;
        }
        else {
            ans = max(ans, range);
            range = 1;
        }
        ans = max(ans, range);
    }
    cout << ans << "\n";
    return 0;
}