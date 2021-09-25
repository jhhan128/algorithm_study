struct UnionFind {
    vector<int> par;

    void init(int sz) {
        par.resize(sz + 1);
        fill(par.begin(), par.end(), -1);
    }

    int find(int v) {
        if (par[v] < 0) return v;
        return par[v] = find(par[v]);
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (par[a] > par[b]) swap(a, b);
        par[a] += par[b], par[b] = a;
    }

    int size(int v) {
        return -par[find(v)];
    }
};
