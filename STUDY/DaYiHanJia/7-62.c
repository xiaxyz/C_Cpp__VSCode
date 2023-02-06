#include <stdio.h>
int main(void)
{
    int n, i;
    float h[10], h1[10];
    char s;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%c%f", &s, &h[i]);
        getchar();
        if (s == 'F')
            h1[i] = h[i] * 1.09;
        else
            h1[i] = 1.0 * h[i] / 1.09;
    }
    for (i = 0; i < n; i++)
        printf("%.2f\n", h1[i]);
    return 0;
}