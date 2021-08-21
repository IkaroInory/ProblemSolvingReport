#include <stdio.h>
#include <math.h>

int isP(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int x, y;
    while (scanf("%d%d", &x, &y) != EOF && (x != 0 || y != 0))
    {
        int rb = 1;
        for (int i = x; i <= y; i++)
        {
            if (isP(i * i + i + 41) == 0)
            {
                rb = 0;
                break;
            }
        }
        if (rb == 1) printf("OK\n");
        else printf("Sorry\n");
    }
    return 0;
}