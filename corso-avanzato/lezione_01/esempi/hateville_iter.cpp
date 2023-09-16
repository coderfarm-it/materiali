const int MAXN = 1e6 + 1;

int prendi[MAXN];
int lascia[MAXN];

prendi[0] = lascia[0] = 0;
for (int i = 1; i <= n; ++i) {
    prendi[i] = lascia[i - 1] + v[i];
    lascia[i] = max(prendi[i - 1], lascia[i - 1]);
}

cout << max(prendi[n], lascia[n]) << "\n";
