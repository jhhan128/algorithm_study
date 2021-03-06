struct bigint {
    vector<int> a;
    int sign;
    
    int size() {
        if (a.empty()) return 0;
        int res = (a.size() - 1) * 9;
        int ca = a.back();
        while (ca) res++, ca /= 10;
        return res;
    }

    string to_string() {
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }

    bigint(): sign(1) {}
    bigint(ll v) { *this = v; }
    bigint(const string &s) { read(s); }
    bigint(const char *s) { string temp = s; read(temp); }

    void operator = (const bigint &v) { sign = v.sign, a = v.a; }
    void operator = (ll v) {
        sign = 1, a.clear();
        if (v < 0) sign = -1, v = -v;
        for (; v > 0; v = v / (int)1e9) 
            a.push_back(v % (int)1e9);
    }

    bigint operator + (const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;
            for (int i = 0, carry = 0; i < (int)max(a.size(), v.a.size()) || carry; i++) {
                if (i == (int)res.a.size()) res.a.push_back(0);
                res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
                carry = res.a[i] >= (int)1e9;
                if (carry) res.a[i] -= (int)1e9;
            } return res;
        } return *this - (-v);
    }

    bigint operator - (const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int)v.a.size() || carry; i++) {
                    res.a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry) res.a[i] += (int)1e9;
                }
                res.trim();
                return res;
            } return -(v - *this);
        } return *this + (-v);
    }

    void operator *= (int v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int)a.size() || carry; i++) {
            if (i == (int)a.size()) a.push_back(0);
            ll cur = a[i] * (ll)v + carry;
            carry = (int)(cur / (int)1e9);
            a[i] = (int)(cur % (int)1e9);
        } trim();
    }

    bigint operator * (int v) const { bigint res = *this; res *= v; return res; }
    void operator *= (ll v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int)a.size() || carry; i++) {
            if (i == (int)a.size()) a.push_back(0);
            ll cur = a[i] * (ll)v + carry;
            carry = (int)(cur / (int)1e9);
            a[i] = (int)(cur % (int)1e9);
        } trim();
    }
 
    bigint operator * (ll v) const { bigint res = *this; res *= v; return res; }
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = (int)1e9 / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());
        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= (int)1e9, r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((ll)1e9 * s1 + s2) / b.a.back(); r -= b * d;
            while (r < (bigint)"0") r += b, --d; q.a[i] = d;
        }
        q.sign = a1.sign * b1.sign, r.sign = a1.sign;
        q.trim(), r.trim(); return make_pair(q, r/norm);
    }

    bigint operator / (const bigint &v) const { return divmod(*this, v).first; }
    bigint operator % (const bigint &v) const { return divmod(*this, v).second; }

    void operator /= (int v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = (int)a.size() - 1, rem = 0; i >= 0; --i) {
            ll cur = a[i] + rem * (ll)1e9;
            a[i] = (int)(cur / v);
            rem = (int)(cur % v);
        }
        trim();
    }

    bigint operator / (int v) const { bigint res = *this; res /= v; return res; }
    int operator % (int v) const {
        if (v < 0) v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (ll)1e9) % v;
        return m * sign;
    }

    void operator += (const bigint &v) { *this = *this + v; }
    void operator -= (const bigint &v) { *this = *this - v; }
    void operator *= (const bigint &v) { *this = *this * v; }
    void operator /= (const bigint &v) { *this = *this / v; }
 
    bool operator < (const bigint &v) const {
        if (sign != v.sign) return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size()* v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator > (const bigint &v) const { return v < *this; }
    bool operator <= (const bigint &v) const { return !(v < *this); }
    bool operator >= (const bigint &v) const { return !(*this < v); }
    bool operator == (const bigint &v) const { return !(*this < v) && !(v < *this); }
    bool operator != (const bigint &v) const { return *this < v || v < *this; }
 
    void trim() {
        while (!a.empty() && !a.back()) a.pop_back();
        if (a.empty()) sign = 1;
    }

    bool isZero() const { return (a.empty() || (a.size() == 1 && !(a[0]))); }

    bigint operator - () const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    ll longValue() const {
        ll res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * (int)1e9 + a[i];
        return res * sign;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+'))
            if (s[pos] == '-') sign = -sign, pos++;
        for (int i = s.size() - 1; i >= pos; i -= 9) {
            int x = 0;
            for (int j = max(pos, i - 9 + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        } trim();
    }

    friend istream& operator >> (istream& stream, bigint &v) { 
        string s; stream >> s; v.read(s); return stream; 
    }

    friend ostream& operator << (ostream& stream, const bigint &v) {
        if (v.sign == -1) stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int)v.a.size() - 2; i >= 0; --i)
            stream << setw(9) << setfill('0') << v.a[i];
        return stream;
    }
 
    static vector<int> cb(const vector<int> &a, int old_digits, int new_digits) {
        vector<ll> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int)p.size(); i++) p[i] = p[i - 1] * 10;
        vector<int> res;
        ll cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && !res.back()) res.pop_back();
        return res;
    } 

    static vector<ll> multiply(const vector<ll> &a, const vector<ll> &b) {
        int n = a.size();
        vector<ll> res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
 
        int k = n >> 1;
        vector<ll> a1(a.begin(), a.begin() + k);
        vector<ll> a2(a.begin() + k, a.end());
        vector<ll> b1(b.begin(), b.begin() + k);
        vector<ll> b2(b.begin() + k, b.end());
        vector<ll> a1b1 = multiply(a1, b1);
        vector<ll> a2b2 = multiply(a2, b2);

        for (int i = 0; i < k; i++) a2[i] += a1[i];
        for (int i = 0; i < k; i++) b2[i] += b1[i];
        vector<ll> r = multiply(a2, b2);

        for (int i = 0; i < (int)a1b1.size(); i++) r[i] -= a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++) r[i] -= a2b2[i];
        for (int i = 0; i < (int)r.size(); i++) res[i + k] += r[i];
        for (int i = 0; i < (int)a1b1.size(); i++) res[i] += a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++) res[i + n] += a2b2[i];

        return res;
    }

    bigint operator * (const bigint &v) const {
        vector<int> a6 = cb(this->a, 9, 6);
        vector<int> b6 = cb(v.a, 9, 6);
        vector<ll> a(a6.begin(), a6.end());
        vector<ll> b(b6.begin(), b6.end());

        while (a.size() < b.size()) a.push_back(0);
        while (b.size() < a.size()) b.push_back(0);
        while (a.size() & (a.size() - 1)) a.push_back(0), b.push_back(0);

        vector<ll> c = multiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int)c.size(); i++) {
            ll cur = c[i] + carry;
            res.a.push_back((int)(cur % (int)1e6));
            carry = (int)(cur / (int)1e6);
        }

        res.a = cb(res.a, 6, 9);
        res.trim();
        return res;
    }
};
