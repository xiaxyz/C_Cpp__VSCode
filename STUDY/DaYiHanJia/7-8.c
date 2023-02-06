#include <stdio.h>
int main(void)
{
    int n, cj[5] = {0}, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x >= 90)
        {
            cj[0]++;
        }
        else if (x < 90 && x >= 80)
        {
            cj[1]++;
        }
        else if (x < 80 && x >= 70)
        {
            cj[2]++;
        }
        else if (x < 70 && x >= 60)
        {
            cj[3]++;
        }
        else
        {
            cj[4]++;
        }
    }
    printf("%d %d %d %d %d", cj[0], cj[1], cj[2], cj[3], cj[4]);
    return 0;
}