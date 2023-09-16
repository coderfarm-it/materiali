vector<int> adj[100000];
vector<bool> vis(100000, false);
vector<int> memo(100000);
int conta(int pos) {
    if (pos == N - 1) return 1;
    if (vis[pos]) return memo[pos];
    vis[pos] = true;
    int tot = 0;
    for (int nodo : adj[pos]) {
        tot += conta(nodo);
    }
    return tot;  // % mod;
}

ans = conta(0);