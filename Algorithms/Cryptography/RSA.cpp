#include <cmath>

using namespace std;

// ax + by = gcd_extended()
long long gcd_extended(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long d = gcd_extended(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

// a^b mod c
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

int isPrime(long long n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

long long RSA_Encryption(long long m, long long n, long long e) {
    return quickpow(m, e, n);
}
long long RSA_Decryption(long long c, long long n, long long d) {
    return quickpow(c, d, n);
}