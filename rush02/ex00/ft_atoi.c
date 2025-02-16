
int	is_space(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + sign * (str[i] - '0');
		i++;
	}
	return (res);
}
//
//#include <stdio.h>
//#include <stdlib.h>
//int main(void) {
//	char s1[] = "2147483647";
//	char s2[] = "-2147483648";
//	char s3[] = " --234ab567";
//	char s4[] = " \t234ab567";
//	printf("%d = %d\n", atoi(s1), ft_atoi(s1));
//	printf("%d = %d\n", atoi(s2), ft_atoi(s2));
//	printf("%d = %d\n", atoi(s3), ft_atoi(s3));
//	printf("%d = %d\n", atoi(s4), ft_atoi(s4));
//	return 0;
//}
