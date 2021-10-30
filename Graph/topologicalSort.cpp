vector<int> topSort() {
    vector<int> ret;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) q.push(i);
    }

    for (int i = 1; i <= n; i++) {
        if (q.empty()) return {};

        int now = q.front();
        q.pop();
        ret.push_back(now);

        for (auto nxt: adj[now]) {
            if (--indegree[nxt] == 0) q.push(nxt);
        }
    }

    return ret;
}
