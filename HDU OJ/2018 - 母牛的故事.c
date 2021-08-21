#include <stdio.h>

int main()
{
    int n, a[60];
    for (int i = 0; i < 60; a[i] = 0, i++);
    for (int i = 1; i < 5; a[i] = i, i++);

    while (~scanf("%d", &n) && n)
    {
        // a[n] = a[n-1] + a[n-3]
        for (int i = 5; i <= n; i++)
            a[i] = a[i - 1] + a[i - 3];
        printf("%d\n", a[n]);
    }
    return 0;
}