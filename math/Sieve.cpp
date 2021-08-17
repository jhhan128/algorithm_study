const int MAX = 100001;
bool isPrime[MAX];

void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i*i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j < MAX; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}
