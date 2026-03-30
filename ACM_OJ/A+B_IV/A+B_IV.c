#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        int sum = 0;
        int x;
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &x);
            sum += x;
        }
        printf("%d\n", sum);
    }
    return 0;
}
    
