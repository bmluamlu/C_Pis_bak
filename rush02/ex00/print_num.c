
#include "rush02.h"

// 10 ^ power 
char	*ten_power(int power)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (power + 2));
	res[0] = '1';
	res[power + 1] = 0;
	i = 0;
	while (++i <= power)
		res[i] = '0';
	return (res);
}

char	*remain_digits(char *n)
{
	int		mod;
	int		remain_size;
	char	*remain;
	int		i;

	mod = ft_strlen(n) % 3;
	remain_size = mod + 1;
	if (mod == 0)
		remain_size = 4;
	remain = (char *)malloc(sizeof(char) * remain_size);
	remain[remain_size - 1] = 0;
	i = -1;
	while (++i < remain_size - 1)
		remain[i] = *(n + i);
	return (remain);
}

void	print_digits_sub1(t_dict *dict, int m, char *str)
{
	if (ft_strlen(str) == 1)
	{
		if (m > 0)
			print_one_digit(str, dict);
	}
	else if (ft_strlen(str) == 2)
		print_two_digit(str, dict);
	else if (ft_strlen(str) == 3)
	{
		print_three_digit(str, dict);
	}
}

void	print_digits_sub2(int n_digit, int remain_size, t_dict *dict, char *n)
{
	char	*ten;

	if (n_digit - remain_size > 0)
	{
		ten = ten_power(n_digit - remain_size);
		write(1, " ", 1);
		print_one_digit(ten, dict);
		free(ten);
	}
	if (*(n + remain_size) != 0)
	{
		write(1, " ", 1);
		print_digits(n + remain_size, dict);
	}
}

void	print_digits(char *n, t_dict *dict)
{
	int		n_digit;
	char	*remain;
	int		m;
	char	*str;
	int		remain_size;

	n_digit = ft_strlen(n);
	remain = remain_digits(n);
	remain_size = ft_strlen(remain);
	m = ft_atoi(remain);
	if (m == 0)
	{
		if (*(n + remain_size) == 0)
			return ;
		print_digits(n + remain_size, dict);
		return ;
	}
	str = ft_itoa(m);
	free(remain);
	print_digits_sub1(dict, m, str);
	print_digits_sub2(n_digit, remain_size, dict, n);
	free(str);
}
