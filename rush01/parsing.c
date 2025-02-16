int ft_atoi(char *str);
int ft_strlen(char *str);
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int validate_input(int argc, char **argv)
{
	int len;

	if (argc != 2)
		return (1);
	len = ft_strlen(argv[1]); 
	if (len == 31)
		return (4);
	else if (len == 47)
		return (6);
	else if (len == 63)
		return (8);
	else if (len == 71)
		return (9);
	return (1);
}

int *parse_input(char *str)
{
	int i;
	int j;
	int *tab;

	if (!(tab = malloc(sizeof(int) * 100)))
		return (0);
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
			tab[j++] = ft_atoi(str + i);
	return (tab);
}