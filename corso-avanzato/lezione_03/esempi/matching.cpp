#include <bits/stdc++.h>
using namespace std;

static constexpr int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<vector<int>> good(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> good[i][j];
        }
    }
    vector<vector<int>> dp(1 << n, vector<int>(n+1));
    dp[0][0] = 1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) continue;
            int old_mask = mask ^ (1 << i);
            for (int j = 1; j <= n; ++j) {
                if (!good[i][j-1]) continue;
                dp[mask][j] += dp[old_mask][j-1];
                dp[mask][j] %= mod;
            }
        }
    }
    cout << dp[(1 << n) - 1][n] << "\n";
}
