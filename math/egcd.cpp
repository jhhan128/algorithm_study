tuple<ll, ll, ll> egcd(ll a, ll b) {
    ll r0 = a, r1 = b;
    ll s0 = 1, s1 = 0, t0 = 0, t1 = 1;
    ll tmp = 0, q = 0;

    while (r1) {
        q = r0 / r1, tmp = r0;
        r0 = r1, r1 = tmp - r1 * q;
        tmp = s0, s0 = s1, s1 = tmp - s1 * q;
        tmp = t0, t0 = t1, t1 = tmp - t1 * q;
    }

    return make_tuple(r0, s0, t0);
}

ll modinv(ll a, ll M) {
    if (gcd(a, M) != 1) return -1;
    ll ret = (get<1>(egcd(a, M)) + M) % M;
    return ret;
}
