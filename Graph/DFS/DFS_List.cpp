const int MAX = 1001;

vector<int> adj[MAX];
bool visited[MAX];

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
        int nxt = adj[v][i];
        if (visited[nxt]) continue;
        dfs(nxt);
    }
}
