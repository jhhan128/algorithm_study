int maps[1001][1001];
bool visited[1001];
int n;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (maps[v][i] && !visited[i]) dfs(i);
    }
}
