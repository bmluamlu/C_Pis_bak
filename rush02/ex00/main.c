
#include "rush02.h"

void	ft_free(char *content, char **lines, t_dict *dict)
{
	int	i;

	free(content);
	i = -1;
	while (lines[++i])
		free(lines[i]);
	free(lines);
	i = -1;
	while (dict[++i].key)
	{
		free(dict[i].key);
		free(dict[i].value);
	}
	free(dict);
}

void	init_args(int argc, char **argv, char **dictname_ptr, char **key_ptr)
{
	*dictname_ptr = "numbers.dict";
	if (argc == 2)
		*key_ptr = argv[1];
	if (argc == 3)
	{
		*dictname_ptr = argv[1];
		*key_ptr = argv[2];
	}
}

int	max_len(t_dict	*dict)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (dict[++i].key)
	{
		if (res < ft_strlen(dict[i].key))
			res = ft_strlen(dict[i].key);
	}
	return (res);
}

int	error_checks(t_dict *dict, char *key)
{
	if (dict_error_check(dict))
		return (1);
	if (ft_strlen(key) > max_len(dict) + 2)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dictname;
	char	*content;
	char	**lines;
	t_dict	*dict;
	char	*key;

	if (!validate_input(argc, argv))
		return (1);
	init_args(argc, argv, &dictname, &key);
	content = file_content(dictname);
	lines = ft_split(content, "\n");
	dict = sep_key_value(lines);
	if (error_checks(dict, key))
	{
		ft_free(content, lines, dict);
		return (1);
	}
	print_digits(key, dict);
	write(1, "\n", 1);
	ft_free(content, lines, dict);
	return (0);
}
