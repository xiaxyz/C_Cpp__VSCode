#include <stdio.h>
int main(void)
{
	char a[10];
	int l = 0, b = 0, d = 0, o = 0, i;
	fflush(stdin);
	for (i = 0; i < 10; i++)
	{
		a[i] = getchar();
		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
		{
			l++;
		}
		else if (a[i] == '\040' || a[i] == '\n')
		{
			b++;
		}
		else if (a[i] >= '0' && a[i] <= '9')
		{
			d++;
		}
		else
		{
			o++;
		}
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d", l, b, d, o);
	return 0;
}