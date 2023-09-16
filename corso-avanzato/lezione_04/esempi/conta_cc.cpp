#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<vector<int>> adj;

void dfs(int v) {
  vis[v] = true;
  for (int u : adj[v]) {
    if (!vis[u]) {
      dfs(u);
    }
  }
}

int main() {
    int n; cin >> n;
    int m; cin >> m;
    adj.resize(n);
    vis.assign(n, false);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ++ans;
            dfs(i);
        }
    }

    cout << ans << "\n";
}
