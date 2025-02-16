
#include "rush02.h"

// constraint: 0 <= n < 10 (but can be used when n >= 10)
void	print_one_digit(char *n, t_dict *dict)
{
	int	i;

	i = -1;
	while (dict[++i].key)
	{
		if (ft_strcmp(dict[i].key, n) != 0)
			continue ;
		ft_putstr(dict[i].value);
		return ;
	}
	return ;
}

void	print_two_digit(char *n, t_dict *dict)
{
	int		m;
	char	*s1;
	char	*s2;

	m = ft_atoi(n);
	if (m % 10 == 0 || m < 20)
		print_one_digit(n, dict);
	else
	{
		s1 = ft_itoa(m / 10 * 10);
		print_two_digit(s1, dict);
		free(s1);
		write(1, " ", 1);
		s2 = ft_itoa(m % 10);
		print_one_digit(s2, dict);
		free(s2);
	}
	return ;
}

void	print_three_digit(char *n, t_dict *dict)
{
	int		m;
	char	*s1;
	char	*s2;

	m = ft_atoi(n);
	if (m % 100 == 0)
	{
		s1 = ft_itoa(m / 100);
		print_one_digit(s1, dict);
		free(s1);
		write(1, " ", 1);
		print_one_digit("100", dict);
		return ;
	}
	s1 = ft_itoa(m / 100 * 100);
	print_three_digit(s1, dict);
	free(s1);
	write(1, " ", 1);
	s2 = ft_itoa(m % 100);
	if (m % 100 >= 10)
		print_two_digit(s2, dict);
	else
		print_one_digit(s2, dict);
	free(s2);
}
