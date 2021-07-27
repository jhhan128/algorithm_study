int maps[1001][1001], visited[1001], visited2[1001];
int n, m, v;
queue<int> q;

void dfs(int v) {
    visited[v] = 1;
    cout << v << ' ';
    for (int i = 1; i <= n; i++) {
        if (maps[v][i] && !visited[i]) dfs(i);
    }
}

void bfs(int v) {
    q.push(v);
    visited2[v] = 1;
    cout << v << ' ';

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (maps[v][i] && !visited2[i]) {
                visited2[i] = 1;
                cout << i << ' ';
                q.push(i);
            }
        }
    }
}
