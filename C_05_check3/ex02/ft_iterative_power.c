
int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = nb;
	while (power > 1)
	{
		res *= nb;
		power--;
	}
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (res);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%i", ft_iterative_power(5, -2));
}
*/