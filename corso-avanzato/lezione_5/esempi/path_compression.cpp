void init() {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
}

int find(int v) {
    return par[v] == v ? v : par[v] = find(par[v]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        par[b] = a;
    }
}
