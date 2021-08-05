vector<int> adj[1001];
bool visited[1001];

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
        int nxt = adj[v][i];
        if (visited[nxt]) continue;
        dfs(nxt);
    }
}
