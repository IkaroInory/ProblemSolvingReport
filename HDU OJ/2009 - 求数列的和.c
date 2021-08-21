#include <stdio.h>
#include <math.h>

int main()
{
    float n, m;
    while (~scanf("%f%f", &n, &m))
    {
        float s = 0;
        while (m--)
        {
            s += n;
            n = sqrt(n);
        }
        printf("%.2f\n", s);
    }
    return 0;
}