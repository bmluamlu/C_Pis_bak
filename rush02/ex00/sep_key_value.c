
#include"rush02.h"
#include <stdlib.h>
#include<stdio.h>

int	ft_strslen(char **strs)
{
	int	count;

	count = 0;
	while (strs[count])
		count++;
	return (count);
}

int	key_len(char *str)
{
	int	key_len;

	key_len = 0;
	while (*str != ':')
	{
		key_len++;
		str++;
	}
	return (key_len);
}

int	value_len(char *str)
{
	int	value_len;

	value_len = 0;
	while (*str != ':')
		str++;
	str++;
	while (*str)
	{
		value_len++;
		str++;
	}
	return (value_len);
}

char	**split_colon(char *str)
{
	char	**pair;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pair = (char **)malloc(sizeof(char *) * 2);
	pair[0] = (char *)malloc(sizeof(char) * (key_len(str) + 1));
	pair[1] = (char *)malloc(sizeof(char) * (value_len(str) + 1));
	while (str[i] != ':')
	{
		pair[0][i] = str[i];
		i++;
	}
	pair[0][i] = 0;
	i++;
	while (str[i])
	{
		pair[1][j] = str[i];
		i++;
		j++;
	}
	pair[1][j] = 0;
	return (pair);
}

t_dict	*sep_key_value(char **strs)
{
	int		i;
	t_dict	*result;
	char	**pair;

	result = (t_dict *)malloc(sizeof(t_dict) * (ft_strslen(strs) + 1));
	i = -1;
	while (strs[++i] != NULL)
	{
		pair = split_colon(strs[i]);
		result[i].key = trim_key(pair[0]);
		result[i].value = trim_value(pair[1]);
		free(pair);
	}
	result[i].key = 0;
	result[i].value = 0;
	return (result);
}
