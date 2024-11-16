#include <stdio.h>
int digitsum(int n)
{
    int x;
    if (n == 0)
    {
        return 0;
    }
    x = n % 10;
    return x + digitsum(n / 10);
}
int main()
{
    printf("%d", digitsum(123));
}