#include <stdio.h>

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int s = 1;
        n--;
        while (n--) s = 2 * (s + 1);
        printf("%d\n", s);
    }
    return 0;
}