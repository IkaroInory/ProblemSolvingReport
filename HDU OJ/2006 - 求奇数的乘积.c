#include <stdio.h>

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int x, s = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if (x % 2 != 0)
                s *= x;
        }
        printf("%d\n", s);
    }
    return 0;
}