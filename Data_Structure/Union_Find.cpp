struct UnionFind {
    vector<int> par;

    void init(int n) {
        par.resize(n+3);

        for (int i = 0; i <= n; i++) {
            par[i] = -1;
        }
    }

    int find(int v) {
        if (par[v] < 0) return v;
        return par[v] = find(par[v]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        par[u] += par[v];
        par[v] = u;
    }

    int size(int v) {
        return -par[find(v)];
    }
};
