static const ll p = 241, m = 1000000007;
ll hash(string a) {
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans = (ans * p + a[i]) % m;
    }
    return ans;
}