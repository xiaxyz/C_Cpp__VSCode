#include <stdio.h>
double fact(int x);
int main(void)
{
	int m, n;
	double result;
	scanf("%d%d", &m, &n);
	result = fact(n) / fact(m) / fact(n - m);
	printf("result = %.0f", result);
	return 0;
}
double fact(int x)
{
	if (x == 0)
	{
		return 1;
	}
	else
	{
		return x * fact(x - 1);
	}
}