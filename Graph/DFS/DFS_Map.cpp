const int MAX = 1001;

int board[MAX][MAX];
bool visited[MAX][MAX];
int w, h;

int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        if (!board[nx][ny] || visited[nx][ny]) continue;

        dfs(nx, ny);
    }
}
