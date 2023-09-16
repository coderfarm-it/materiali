struct nodo {
    int somma, pref_max, suff_max, subarray_max;
};

nodo unisci(nodo a, nodo b) {
    nodo res;
    res.somma = a.somma + b.somma;
    res.pref_max = max(a.pref_max, a.somma + b.pref_max);
    res.suff_max = max(b.suff_max, b.somma + a.suff_max);
    int caso1 = max(a.subarray_max, b.subarray_max);
    int caso2 = a.suff_max + b.pref_max;
    res.subarray_max = max(caso1, caso2);
    return res;
}