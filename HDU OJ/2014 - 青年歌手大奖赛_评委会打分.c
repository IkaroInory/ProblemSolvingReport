#include <stdio.h>

int main()
{
    int n, a[100];
    while (~scanf("%d", &n))
    {
        int mark = 0;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (a[i] > a[j])
                {
                    a[i] = a[i] + a[j];
                    a[j] = a[i] - a[j];
                    a[i] = a[i] - a[j];
                }
        for (int i = 1; i < n - 1; i++) mark += a[i];
        printf("%.2f\n", (float)mark / (n - 2));
    }
    return 0;
}