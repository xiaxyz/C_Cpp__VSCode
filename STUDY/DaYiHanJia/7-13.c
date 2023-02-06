#include <stdio.h>
int main(void)
{
    int x, n, i, j = 0, a[100];
    scanf("%d%d", &x, &n);
    do
    {
        scanf("%d", &a[j]);
    } while (a[j++] >= 0);
    for (i = 0; i <= n; i++)
    {
        if (a[i] >= 0 && a[i] < x && i < n)
            printf("Too small\n");
        else if (a[i] > x && i < n)
            printf("Too big\n");
        else if (a[i] == x && i == 0)
        {
            printf("Bingo!");
            break;
        }
        else if (a[i] == x && i > 0 && i <= 2 && i < n)
        {
            printf("Lucky You!");
            break;
        }
        else if (a[i] == x && i > 2 && i < n)
        {
            printf("Good Guess!");
            break;
        }
        else if (a[i] < 0 || i == n)
        {
            printf("Game Over");
            break;
        }
    }
    return 0;
}