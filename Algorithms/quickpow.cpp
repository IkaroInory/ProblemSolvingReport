long long quickpow(long long a, long long b, long long c) {
    long long res = 1;
    long long temp = a % c;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * temp) % c;
        b /= 2;
        temp = (temp * temp) % c;
    }
    return res;
}