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
            dp[i][j] = dp[i][j-1];
            for (int jj = (j-1)/2+1; jj <= j/2; ++jj) {
                dp[i][j] = (dp[i][j] + dp[i-1][jj]) % mod;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << "\n";
}
