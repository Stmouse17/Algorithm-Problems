#include <stdio.h>

int main()
{
    int N;
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", a + b);
        }
    }
    return 0;
}