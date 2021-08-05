int maps[1001][1001];
int visited[1001];
int n;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited2[v] = 1;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (maps[v][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
