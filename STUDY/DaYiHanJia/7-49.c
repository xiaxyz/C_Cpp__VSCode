#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[21][11];
    int n = 0, i = 0, f;
    do
    {
        gets(a[i]);
        i++;
    } while (strcmp(a[i - 1], "#"));
    n = i - 1;
    do
    {
        f = 0;
        for (i = 1; i < n; i++)
        {
            if (strlen(a[i - 1]) > strlen(a[i]))
            {
                char temp[11];
                strcpy(temp, a[i]);
                strcpy(a[i], a[i - 1]);
                strcpy(a[i - 1], temp);
                f = 1;
            }
        }
    } while (f != 0);
    for (i = 0; i < n; i++)
        printf("%s ", a[i]);
    return 0;
}