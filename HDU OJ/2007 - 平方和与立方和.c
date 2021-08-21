#include <stdio.h>

int main()
{
    int m, n;
    while (~scanf("%d %d", &m, &n))
    {
        int ss = 0, sc = 0, t = 0;
        if (m > n) { t = m; m = n; n = t; }
        for (int i = m; i <= n; i++)
            if (i % 2 == 0) ss += i * i;
            else sc += i * i * i;
        printf("%d %d\n", ss, sc);
    }
    return 0;
}