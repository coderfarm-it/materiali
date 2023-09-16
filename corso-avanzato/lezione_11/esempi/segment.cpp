#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int n;
    vector<long long> t;
    Segment(int _n, vector<int> a) {
        for (n = 1; n < _n; n <<= 1);
        t.resize(2 * n);
    }
    long long query(int p) {
        int ans = 0;
        for (p += n; p > 0; p >>= 1) {
            ans += t[p];
        }
        return ans;
    }
    long long query(int i, int tl, int tr, int p) {
        if (p < tl || tr < p) return 0;
        if (tl == tr) {
            return t[i];
        } else {
            int tm = (tl + tr) / 2;
            if (p <= tm) {
                return t[i] + query(2*i, tl, tm, p);
            } else {
                return t[i] + query(2*i+1, tm+1, tr, p);
            }
        }
    }
    void update(int i, int tl, int tr, int l, int r, long long x) {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) t[i] += x;
        else {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, l, r, x);
            update(2*i+1, tm+1, tr, l, r, x);
        }
    }
    void update(int l, int r, long long x) {
        update(1, 0, n-1, l, r, x);
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
    for (int i = 0, t, a, b, x; i < q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> x;
            st.update(a-1, b, x);
        } else {
            cin >> a;
            cout << st.query(a-1) << "\n";
        }
    }
}
