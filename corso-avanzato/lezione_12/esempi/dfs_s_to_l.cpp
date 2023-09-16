set<int> dfs(int pos, int par) {
    set<int> res;
    for (int x : adj[pos]) {
        if (x == par) continue;
        set<int> tmp = dfs(x, pos);
        for (int y : tmp) res.insert(y);
    }
    ans[pos] = res.size();
    res.insert(color[pos]);
    return res;
}