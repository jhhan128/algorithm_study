const int MAX = 1001;

int adj[MAX][MAX];
bool visited[MAX];
int n;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
