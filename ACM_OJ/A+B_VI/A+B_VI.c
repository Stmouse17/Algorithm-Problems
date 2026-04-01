#include <stdio.h>

int main()
{
    int N;  //Number of lines in a set of equations
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            int M;  //Number of addends in each equations
            int x;  //Addends
            int sum = 0;    //Results
            scanf("%d", &M);
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &x);
                sum += x;
            }
            printf("%d\n", sum);
            if (i != N - 1)
                printf("\n");
        }
    }
    return 0;
}