
int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	if (nb < 0)
	{
		return (0);
	}
	return (res);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%i", ft_iterative_factorial(3));
}
*/