#include <stdio.h>

int factor(int n)
{
    int s = 1;
    for(int i = 1; i <= n; i++)
    {
        s *= i;
    }
    return s;
}

double e(int x)
{
    double s = 0.0;
    for(int i = 0; i <= x; i++)
    {
        s += 1.0 / factor(i);
    }
    return s;
}

int main()
{
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for(int i = 3; i < 10; i++)
        printf("%d %.9lf\n", i, e(i));
	return 0;
}