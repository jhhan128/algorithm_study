// 역추적: http://boj.kr/c1d855b83458461381de180677f4b4c0

const int MAX = 20001;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[MAX];
int dist[MAX];

void dijkstra(int v) {
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    memset(dist, INF, sizeof(dist));

    dist[v] = 0;
    pq.push(make_pair(0, v));

    while (!pq.empty()) {
        int c = pq.top().first;
        int n = pq.top().second;
        pq.pop();

        if (dist[n] < c) continue;
        for (int i = 0; i < adj[n].size(); i++) {
            int nn = adj[n][i].first;
            int nc = c + adj[n][i].second;

            if (dist[nn] > nc) {
                dist[nn] = nc;
                pq.push(make_pair(nc, nn));
            }
        }
    }
}
