static const ll mod = 1000000007;
vector<ll> fact = {1};
vector<ll> invfact = {1};

ll binom(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

void precalc(int n) {
    for (int i = 1; i <= n; i++) {
        fact.push_back(fact.back() * i % mod);
        invfact.push_back(pot(fact[i], mod - 2) % mod);
    }
}