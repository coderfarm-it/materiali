#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int n;
    vector<long long> t;
    Segment(int _n, vector<int> a) {
        for (n = 1; n < _n; n <<= 1);
        t.resize(2 * n);
        for (int i = 0; i < _n; ++i) {
            t[i + n] = a[i];
        }
        for (int i = n-1; i > 0; --i) {
            t[i] = t[2*i] + t[2*i+1];
        }
    }
    void update(int p, int v) {
        for (t[p += n] = v; p > 1; p >>= 1) {
            t[p >> 1] = t[p] + t[p ^ 1];
        }
    }
    void update(int i, int tl, int tr, int p, int v) {
        if (p < tl || tr < p) return;
        if (tl == tr) {
            t[i] = v;
        } else {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = t[2*i] + t[2*i+1];
        }
    }
    long long query(int i, int tl, int tr, int l, int r) {
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) return t[i];
        else {
            int tm = (tl + tr) / 2;
            return query(2*i, tl, tm, l, r) +
                   query(2*i+1, tm+1, tr, l, r);
        }
    }
    long long query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int main() {
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Segment st(n, a);
    for (int i = 0, t, a, b; i < q; ++i) {
        cin >> t >> a >> b;
        if (t == 1) {
            st.update(a-1, b);
        } else {
            cout << st.query(a-1, b-1) << "\n";
        }
    }
}
