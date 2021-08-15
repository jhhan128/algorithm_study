const int MAX = 501;
const ll INF = 0x3f3f3f3f3f3f3f3f;

vector<pair<int, int>> adj[MAX];
ll dist[MAX];
int n, m;

bool bellmanFord(int v) {
    memset(dist, (int)INF, sizeof(dist));
    dist[v] = 0;
    bool hasMinusCycle = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto &p: adj[j]) {
                int nxt = p.first;
                int w = p.second;

                if (dist[j] == INF) continue;
                if (dist[nxt] > dist[j]+w) {
                    dist[nxt] = dist[j] + w;
                    if (i == n) hasMinusCycle = 1;
                }
            }
        }
    }

    return hasMinusCycle;
}
