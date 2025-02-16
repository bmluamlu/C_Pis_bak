
#include "rush02.h"
#include <unistd.h>

int	is_number(char *str)
{
	int	i;
	int	is_zero;

	i = 0;
	is_zero = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		if (str[i] != '0')
		{
			is_zero = 0;
		}
		i++;
	}
	if (is_zero == 1)
		return (0);
	return (1);
}

int	validate_input(int argc, char **argv)
{
	unsigned int	len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if (is_number(argv[1]) == 0 || len == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		return (1);
	}
	else if (argc == 3)
	{
		len = ft_strlen(argv[2]);
		if (is_number(argv[2]) == 0 || len == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		return (1);
	}
	write(1, "Error\n", 6);
	return (0);
}

//int	main(int argc, char *argv[])
//{
//	if (!(validate_input(argc, argv)))
//		return (0);
//	return (0);
//}
/*
int	is__space(unsigned int i, unsigned int len, char c)
{
	if ((i < len) && (c == 32 || (c >= 9 && c <= 13)))
		return (1);
	else
		return (0);
}

int	is_positive(char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (is__space(i, len, str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	else if (str[i] == '0')
	{
		while (i < len && str[i] == '0')
			i++;
		if (i == len || str[i] < '0' || str[i] > '9')
			return (0);
	}
	if (str[i] >= '1' && str[i] <= '9')
		return (1);
	return (0);
}


*/
