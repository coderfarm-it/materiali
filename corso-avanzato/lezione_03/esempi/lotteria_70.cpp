#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 1; i <= m; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int jj = 1; jj <= j/2; ++jj) {
                dp[i][j] += dp[i-1][jj];
                dp[i][j] %= mod;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << "\n";
}
