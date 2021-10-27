bool lineIntersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    int c1 = ccw(x1, y1, x2, y2, x3, y3);
    int c2 = ccw(x1, y1, x2, y2, x4, y4);
    int c3 = ccw(x3, y3, x4, y4, x1, y1);
    int c4 = ccw(x3, y3, x4, y4, x2, y2);

    bool f1 = min(x1, x2) > max(x3, x4);
    bool f2 = min(y1, y2) > max(y3, y4);
    bool f3 = min(x3, x4) > max(x1, x2);
    bool f4 = min(y3, y4) > max(y1, y2);

    if (c1 * c2 > 0 || c3 * c4 > 0) return 0;
    else if (c1 || c2 || c3 || c4) return 1;
    else if (f1 || f2 || f3 || f4) return 0;
    else return 1;
}
