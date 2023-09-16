int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    b = lift(b, dep[b] - dep[a]);
    if (a == b) return a;
    // IMPORTANTE: le potenze di 2 dalla più grande
    for (int i = LOG-1; i >= 0; --i) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    assert(up[0][a] == up[0][b]);
    return up[0][a];
}
