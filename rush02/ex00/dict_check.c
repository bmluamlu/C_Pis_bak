
#include"rush02.h"
#define DICT_ERROR 1
#define SUCCESS 0

int	check_dup_key(t_dict *dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].key)
	{
		j = i + 1;
		while (dict[j].key)
		{
			if (ft_strcmp(dict[i].key, dict[j].key) == 0)
			{
				return (DICT_ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_number_key(t_dict *dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].key)
	{
		j = 0;
		while (dict[i].key[j])
		{
			if (dict[i].key[j] < '0' || '9' < dict[i].key[j])
				return (DICT_ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	dict_error_check(t_dict *dict)
{
	if (check_dup_key(dict) == DICT_ERROR
		|| check_number_key(dict) == DICT_ERROR)
	{
		write(1, "Dict Error\n", 11);
		return (DICT_ERROR);
	}
	return (SUCCESS);
}
