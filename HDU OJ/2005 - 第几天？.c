#include <stdio.h>

int isLeapY(int y)
{
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) return 1;
    else return 0;
}

int main()
{
    int y, m, d;
    while (~scanf("%d/%d/%d", &y, &m, &d))
    {
        int s = 0;
        int Md[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isLeapY(y) == 1) Md[1]++;

        for (int i = 0; i < m - 1; i++)
        {
            s += Md[i];
        }
        printf("%d\n", s + d);
    }
    return 0;
}