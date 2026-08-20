#include<bits/stdc++.h>

using namespace std;

int find_closest(const vector<int>& arr, int target) {
    auto it = lower_bound(arr.begin(), arr.end(), target);
    
    if (it == arr.begin()) return *it;
    if (it == arr.end()) return *(it - 1);
    
    int after = *it;
    int before = *(it - 1);
    
    if (abs(after - target) < abs(target - before)) {
        return after;
    } else {
        return before;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> series(n);
    for (int i = 0; i < n; i++) {
        cin >> series[i];
    }
    
    vector<int> fill_list(m);
    for (int i = 0; i < m; i++) {
        cin >> fill_list[i];
    }
    
    vector<int> unique_vals = fill_list;
    sort(unique_vals.begin(), unique_vals.end());
    unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
    
    vector<int> result = series, left_val(n + 1), right_val(n + 1);
    int last_non_zero = -1;
    for (int i = 0; i < n; i++) {
        if (series[i] != 0) {
            last_non_zero = series[i];
        }
        left_val[i] = last_non_zero;
    }
    
    last_non_zero = -1;
    for (int i = n-1; i >= 0; i--) {
        if (series[i] != 0) {
            last_non_zero = series[i];
        }
        right_val[i] = last_non_zero;
    }
    
    for (int i = 0; i < n; i++) {
        if (result[i] != 0) continue;
        int prev_val = left_val[i];
        int next_val = right_val[i];
        if (prev_val == -1 && next_val == -1) {
            result[i] = unique_vals[unique_vals.size() / 2];
        } else if (prev_val == -1) {
            result[i] = find_closest(unique_vals, next_val);
        } else if (next_val == -1) {
            result[i] = find_closest(unique_vals, prev_val);
        } else {
            int low = min(prev_val, next_val);
            int high = max(prev_val, next_val);

            auto it = lower_bound(unique_vals.begin(), unique_vals.end(), low);
            if (it != unique_vals.end() && *it <= high) {
                result[i] = *it;
            } else {
                int cand1 = find_closest(unique_vals, low);
                int cand2 = find_closest(unique_vals, high);
                int cost1 = abs(cand1 - prev_val) + abs(cand1 - next_val);
                int cost2 = abs(cand2 - prev_val) + abs(cand2 - next_val);
                result[i] = (cost1 <= cost2) ? cand1 : cand2;
            }
        }
    }
    
    long long total_diff = 0;
    for (int i = 1; i < n; i++) {
        total_diff += abs(result[i] - result[i-1]);
    }
    
    cout << total_diff << "\n";
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << "\n";
    
    return 0;
}