const int MAX = 1001;

int adj[MAX][MAX];
bool visited[MAX];
int n;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) dfs(i);
    }
}
