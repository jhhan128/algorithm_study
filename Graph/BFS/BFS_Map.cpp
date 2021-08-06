const int MAX = 1001;

int board[MAX][MAX];
bool visited[MAX][MAX];
int w, h;

int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = 1;

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ax = nx + dx[i];
            int ay = ny + dy[i];

            if (ax < 0 || ay < 0 || ax >= w || ay >= h) continue;
            if (!board[ax][ay] || visited[ax][ay]) continue;

            q.push({ ax, ay });
            visited[ax][ay] = 1;
        }
    }
}
