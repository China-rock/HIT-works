#include<stdio.h>

int main(void)
{
    int n, a, b;
    short int t = 1;
    scanf("%d", &n);
    if(n < 0)
    {
        t = -1;
        n = -n;
    }
    a = (n / 100) * t;
    b = (n % 100) * t;
    printf("%d,%d\n", a, b);
    printf("%d,%d,%d\n", a + b, a - b, a * b);
    if(b != 0)
        printf("%d,%d\n", a / b, a % b);
    else
        printf("The second operator is zero!\n");
    return 0;
}