#include <stdio.h>

int main()
{
    double r;
    while (~scanf("%lf", &r))
    {
        printf("%.2lf\n", r < 0 ? -r : r);
    }
    return 0;
}