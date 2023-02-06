#include <stdio.h>
#include <math.h>
int main(void)
{
	int a, b, c;
	float area, p, s;
	scanf("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		s = (a + b + c) / 2.0;
		area = pow(s * (s - a) * (s - b) * (s - c), 0.5);
		p = a + b + c;
		printf("area = %.2f; perimeter = %.2f", area, p);
	}
	else
	{
		printf("These sides do not correspond to a valid triangle");
	}
	return 0;
}