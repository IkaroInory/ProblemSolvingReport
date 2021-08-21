#include <stdio.h>

int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        float x;
        int ne = 0, ze = 0, po = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%f", &x);
            if (x < 0) ne++;
            else if (x == 0) ze++;
            else po++;
        }
        printf("%d %d %d\n", ne, ze, po);
    }
    return 0;
}