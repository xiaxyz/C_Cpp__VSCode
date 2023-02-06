#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *subchr(char *a);

int main(void)
{
    char a[] = "sad fhs akjf", *b, *c;
    b = a;
    while (1)
    {
        c = subchr(b);
        printf("%s\n",c);
        b = strchr(b, ' ');
        if (b == NULL)
            break;
        b++;
    }
    return 0;
}

char *subchr(char *a)
{
    char *b;
    b = (char *)malloc(sizeof(a));
    strcpy(b, a);
    b = strtok(b, " ");
    return b;
}