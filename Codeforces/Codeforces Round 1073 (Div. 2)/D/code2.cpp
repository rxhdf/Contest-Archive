#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long MOD = 998244353;
long long C[105][105];
long long dp[105][105][105]; // dp[index][current_balance][length]

void precompute() {
    // Precompute Binomial Coefficients
    for (int i = 0; i <= 100; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            for (int l = 0; l <= n + 1; l++) {
                dp[i][j][l] = 0;
            }
        }
    }

    dp[n][0][0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= n - i; l++) {
                long long res = dp[i + 1][j][l];
                if (l > 0) {
                    if (s[i] == '(') {
                        if (j + 1 <= n) {
                            res = (res + dp[i + 1][j + 1][l - 1]) % MOD;
                        }
                    } else {
                        if (j > 0) {
                            res = (res + dp[i + 1][j - 1][l - 1]) % MOD;
                        }
                    }
                }
                dp[i][j][l] = res;
            }
        }
    }

    long long total_score = 0;
    for (int m = 1; m * 2 <= n; m++) {
        if (m < 2) continue;
        long long total_rbs = dp[0][0][2 * m];
        long long bad_rbs = 0;
        int open_cnt_prefix = 0; 

        for (int k = 0; k < n; k++) {
            if (s[k] == '(') {
                if (m - 2 >= 0 && open_cnt_prefix >= m - 2) {
                    long long ways_prefix = C[open_cnt_prefix][m - 2];
                    if (m - 1 <= n && m + 1 <= n) {
                        long long ways_suffix = dp[k + 1][m - 1][m + 1];
                        long long combinations = (ways_prefix * ways_suffix) % MOD;
                        bad_rbs = (bad_rbs + combinations) % MOD;
                    }
                }
                open_cnt_prefix++;
            }
        }
        long long good_rbs = (total_rbs - bad_rbs + MOD) % MOD;
        long long score_val = (2 * m - 2);
        long long contribution = (good_rbs * score_val) % MOD;
        
        total_score = (total_score + contribution) % MOD;
    }

    cout << total_score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}