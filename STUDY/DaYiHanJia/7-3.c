#include <stdio.h>
int main(void)
{
	int y, i, flag = 0;
	scanf("%d", &y);
	if (y <= 2000 || y > 2100)
	{
		flag = 2;
	}
	if (flag == 0)
	{
		for (i = 2001; i <= y; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			{
				printf("%d\n", i);
				flag = 1;
			}
		}
	}
	if (flag == 0)
	{
		printf("None");
	}
	if (flag == 2)
	{
		printf("Invalid year!");
	}
	return 0;
}