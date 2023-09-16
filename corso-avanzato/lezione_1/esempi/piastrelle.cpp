#include <bits/stdc++.h>
using namespace std;

void solve(int n, string prefix = "") {
    if (n < 0) return;
    if (n == 0) {
        cout << prefix << "\n";
    } else {
        solve(n - 1, prefix + "[O]");
        solve(n - 2, prefix + "[OOOO]");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n; cin >> n;
    solve(n);
}

