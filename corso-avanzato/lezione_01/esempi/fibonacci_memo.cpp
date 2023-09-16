const int MAXN = 1e6;
const int MOD = 1e9 + 7;

bool vis[MAXN]; // ho già calcolato fib(i)?
int memo[MAXN]; // i-esimo numero di Fibonacci

int fib(int n) {
  if (vis[n]) {
    return memo[n];
  }
  vis[n] = true;
  if (n <= 1) {
    return memo[n] = 1;
  } else {
    return memo[n] = (fib(n-1) + fib(n-2)) % MOD;
  }
}
