#include <stdio.h>
#include <math.h>

int main()
{
    int R[16];
    int G[16];
    int B[16];
    int r, g, b;
    for (int i = 0; i < 16; i++)
    {
        scanf("%d", &R[i]);
        scanf("%d", &G[i]);
        scanf("%d", &B[i]);
    }
    while (scanf("%d %d %d", &r, &g, &b) != EOF && !(r == -1 && g == -1 && b == -1))
    {
        int l_index = 0;
        float l = 500.0;
        for (int i = 0; i < 16; i++)
        {
            float l0 = sqrt((r - R[i]) * (r - R[i]) + (g - G[i]) * (g - G[i]) + (b - B[i]) * (b - B[i]));
            if (l0 < l)
            {
                l = l0;
                l_index = i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, R[l_index], G[l_index], B[l_index]);
    }
    return 0;
}