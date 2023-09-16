// 100/100 https://cses.fi/problemset/task/1750/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

static constexpr int LOG = 31;
vector<int> up[LOG];

void build(int n, vector<int> p) {
    for (int i = 0; i < LOG; ++i) {
        up[i].resize(n);
    }
    for (int i = 0; i < n; ++i) {
        up[0][i] = p[i];
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            up[j][i] = up[j-1][up[j-1][i]];
        }
    }
}

int lift(int v, int k) {
    for (int i = 0; i < LOG; ++i) {
        if (k & (1 << i)) {
            v = up[i][v];
        }
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int q; cin >> q;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; --p[i];
    }
    build(n, p);
    for (int x, k; q--;) {
        cin >> x >> k; --x;
        cout << lift(x, k)+1 << "\n";
    }
}
