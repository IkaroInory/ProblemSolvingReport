#include <stdio.h>

int main()
{
    int m, n;
    while (~scanf("%d%d", &m, &n))
    {
        int sw = 0;
        for (int i = m; i <= n; i++)
            if (i == (i / 100) * (i / 100) * (i / 100) + (i / 10 % 10) * (i / 10 % 10) * (i / 10 % 10) + (i % 10) * (i % 10) * (i % 10))
            {
                if (sw == 0) printf("%d", i);
                else printf(" %d", i);
                sw++;
            }
        if (sw == 0)
            printf("no");
        printf("\n");
    }
    return 0;
}