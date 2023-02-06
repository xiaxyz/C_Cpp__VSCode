#include <stdio.h>
int main(void)
{
    int starth, startm, endh, endm, h, m;
    scanf("%2d%2d%2d%2d", &starth, &startm, &endh, &endm);
    if (endm < startm)
    {
        m = endm - startm + 60;
        h = endh - starth - 1;
    }
    else
    {
        m = endm - startm;
        h = endh - starth;
    }
    printf("%02d:%02d", h, m);
    return 0;
}