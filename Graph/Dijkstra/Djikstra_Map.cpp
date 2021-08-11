const int MAX = 1001;
const int INF = 0x3f3f3f3f;

int board[MAX][MAX];
int dist[MAX][MAX];
int w, h;

int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

void dijkstra(int x, int y) {
    using pii = pair<int, pair<int, int>>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    memset(dist, INF, sizeof(dist));

    dist[x][y] = board[x][y];
    pq.push({ dist[x][y], { x, y } });

    while (!pq.empty()) {
        int c = pq.top().first;
        int nx = pq.top().second.first;
        int ny = pq.top().second.second;
        pq.pop();

        if (c != dist[nx][ny]) continue;
        for (int i = 0; i < 4; i++) {
            int ax = nx + dx[i];
            int ay = ny + dy[i];

            if (ax < 0 || ay < 0 || ax >= w || ay >= h) continue;
            if (dist[ax][ay] > dist[nx][ny] + board[ax][ay]) {
                dist[ax][ay] = dist[nx][ny] + board[ax][ay];
                pq.push({ dist[ax][ay], { ax, ay } });
            }
        }
    }
}
