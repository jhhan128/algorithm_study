vector<int> adj[1001];
bool visited[1001];

void bfs(int v) {
    queue<int> q;
    visited[v] = 1;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 0; i < adj[v].size(); i++) {
            int nxt = adj[v][i];
            if (!visited[nxt]) {
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}
