#include <stdio.h>
#include <string.h>
int main(void)
{
    char x[4][3] = {0};
    x[1][0] = '\0';
    x[1][1] = '\0';
    x[1][2] = '\0';
    if (x[1] == NULL)
        printf("1");
    return 0;
}