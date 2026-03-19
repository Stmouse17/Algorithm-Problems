#include <stdio.h>

//Time Complexity: T(n)=2T(n-1)+1=2^n-1

void Hanoi(int n, char from, char aux, char to) //aux-auxiliary
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    Hanoi(n - 1, from, to, aux);
    printf("Move disk %d from %c to %c\n", n, from, to);
    Hanoi(n - 1, aux, from, to);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}
