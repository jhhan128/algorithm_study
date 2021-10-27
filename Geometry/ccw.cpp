int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll res = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}
