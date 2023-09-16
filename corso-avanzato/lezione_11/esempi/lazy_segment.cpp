#include <bits/stdc++.h>
using namespace std;

struct nodo {
    int somma = 0;
    int aggiungi = 0;
};
vector<nodo> t;
void propaga(int i, int tl, int tr) {
    t[i].somma += t[i].aggiungi * (tr - tl + 1);
    if (tl != tr) {
        t[2 * i].aggiungi += t[i].aggiungi;
        t[2 * i + 1].aggiungi += t[i].aggiungi;
    }
    t[i].aggiungi = 0;
}
void update(int i, int tl, int tr, int l, int r, long long x) {
    propaga(i, tl, tr);
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) {
        t[i].aggiungi += x;
        propaga(i, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * i, tl, tm, l, r, x);
    update(2 * i + 1, tm + 1, tr, l, r, x);
    t[i].somma = t[2 * i].somma + t[2 * i + 1].somma;
}
int query(int i, int tl, int tr, int l, int r) {
    propaga(i, tl, tr);
    if (r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return t[i].somma;
    int tm = (tl + tr) / 2;
    return query(2 * i, tl, tm, l, r) + query(2 * i + 1, tm + 1, tr, l, r);
}