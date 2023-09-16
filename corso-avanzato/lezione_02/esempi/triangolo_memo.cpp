#include <bits/stdc++.h>
using namespace std;

static constexpr int N = 100;

int n;
int v[N][N];
int dp[N][N];
bool vis[N][N];

int solve(int i, int j) {
    if (i == n) return 0;
    if (vis[i][j]) {
        return dp[i][j];
    }
    vis[i][j] = true;
    int sx = solve(i+1, j);
    int dx = solve(i+1, j+1);
    return dp[i][j] = v[i][j] + max(sx, dx);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> v[i][j];
        }
    }

    cout << solve(0, 0) << "\n";
}
