set<int> k[200005];
void dfs(int pos, int par) {
    for (int x : adj[pos]) {
        if (x == par) continue;
        dfs(x, pos);
        if (k[x].size() > k[pos].size()) swap(k[x], k[pos]);
        for (int y : k[x]) k[pos].insert(y);
    }
    k[pos].insert(color[pos]);
    ans[pos] = k[pos].size();
}