#include <stdio.h>

int main()
{
    int m;
    while (~scanf("%d", &m))
    {
        int x;
        for (int i = 0; i < m; i++)
        {
            int symbol = 1;
            float s = 0.0;
            scanf("%d", &x);
            for (int j = 1; j <= x; j++)
            {
                if (symbol == 1)
                {
                    s += 1.0 / j;
                    symbol--;
                }
                else
                {
                    s -= 1.0 / j;
                    symbol++;
                }
            }
            printf("%.2f\n", s);
        }
    }
    return 0;
}