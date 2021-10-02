string toBase(ll n, int base) {
    string ret = "";
    bool isNeg = (n < 0);
    if (isNeg) n = -n;
    
    do {
        char dig = n % base;
        if (dig < 10) dig += '0';
        else dig = dig + 'A' - 10;
        
        ret.push_back(dig);
        n /= base;
    } while (n > 0);
    
    reverse(ret.begin(), ret.end());
    return (isNeg ? "-" : "") + ret;
}
