int memo[MAXN];
bool vis[MAXN];
//stato: N = numero di case del prefisso
int solve(int N) {
    if (N < 0) return 0;
    if (vis[N]) return memo[N];
    vis[N] = true;

    //transizione
    int prendo = V[N] + solve(N - 2);
    int nonPrendo = solve(N - 1);

    return memo[N] = max(prendo, nonPrendo);
}