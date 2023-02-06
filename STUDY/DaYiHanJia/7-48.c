#include <stdio.h>
#include <string.h>
int main(void)
{
    int n, num, a, b, c, sum, max_num, max_sum;
    char name[11], max_name[11];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%s%d%d%d", &num, name, &a, &b, &c);
        sum = a + b + c;
        if (i == 0)
        {
            max_sum = sum;
            max_num = num;
            strcpy(max_name, name);
        }
        else
        {
            if (sum > max_sum)
            {
                max_sum = sum;
                max_num = num;
                strcpy(max_name, name);
            }
        }
    }
    printf("%s %05d %d", max_name, max_num, max_sum);
    return 0;
}