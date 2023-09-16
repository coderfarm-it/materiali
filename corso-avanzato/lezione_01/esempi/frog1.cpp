int memo[MAXN];
bool vis[MAXN];
int solve(int pos) {
    if (pos == N) return 0;
    if (vis[pos]) return memo[pos];
    vis[pos] = true;

    int salto1 = solve(pos + 1) + abs(h[pos] - h[pos + 1]);
    if (pos + 1 == N) return memo[pos] = salto1;
    int salto2 = solve(pos + 2) + abs(h[pos] - h[pos + 2]);
    return memo[pos] = min(salto1, salto2);
}