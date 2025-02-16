
int	ft_sqrt(int nb)
{
	int	p;

	if (nb <= 0)
	{
		return (0);
	}
	if (nb == 1)
	{
		return (1);
	}
	p = 2;
	if (nb >= 2)
	{
		while (p <= nb / p)
		{
			if (p * p == nb)
			{
				return (p);
			}
			p++;
		}
	}
	return (0);
}

/*
#include <stdio.h>

int main(void)
{
	printf("sqrt of %d is %d\n", 2147483647, ft_sqrt(2147483647));
    return (0);
}
*/