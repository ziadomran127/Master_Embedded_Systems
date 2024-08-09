#include <stdio.h>

int i = 0;
int sum = 0;

int main()
{
	if (i <= 100)
	{
		sum += i;
		i++;
		main();
	}

	if (i==101)
	{
		printf(" %d ", sum);
		i= 102;
	}

	return 0;
}