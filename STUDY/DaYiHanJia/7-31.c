#include <stdio.h>
#include <string.h>
int main(void)
{
    int n, i;
    char name[10][31], max_name[31], min_name[31];
    double price[10], max_price, min_price;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        getchar();
        gets(name[i]);
        scanf("%lf", &price[i]);
        if (i == 0)
        {
            strcpy(max_name, name[i]);
            max_price = price[i];
            strcpy(min_name, name[i]);
            min_price = price[i];
        }
        else
        {
            if (price[i] > max_price)
            {
                strcpy(max_name, name[i]);
                max_price = price[i];
            }
            if (price[i] < min_price)
            {
                strcpy(min_name, name[i]);
                min_price = price[i];
            }
        }
    }
    printf("%.2lf, %s\n%.2lf, %s", max_price, max_name, min_price, min_name);
    return 0;
}