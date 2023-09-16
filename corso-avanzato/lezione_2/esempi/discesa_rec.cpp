#include <bits/stdc++.h>
using namespace std;

static constexpr int N = 10;

int n;
int v[N][N];

// i: di quanti piani sono sceso
// j: sul piano i, dove mi trovo
int solve(int i, int j) {
    if (i == n) return 0;
    int sx = solve(i+1, j);
    int dx = solve(i+1, j+1);
    return v[i][j] + max(sx, dx);
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
