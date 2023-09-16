#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<vector<int>> prf(n+1, vector<int>(m+1));
    for (int i = 1; i <= m; ++i) {
        dp[1][i] = 1;
        prf[1][i] = prf[1][i-1] + 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = prf[i-1][j/2];
            prf[i][j] = prf[i][j-1] + dp[i][j];
            prf[i][j] %= mod;
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << "\n";
}
