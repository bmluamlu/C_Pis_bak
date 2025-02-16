
#include <stdlib.h>

int	is_delimiter(char c, char *charset)
{
	int	i;

	if (c == 0)
		return (1);
	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (is_delimiter(str[i], charset))
			continue ;
		if (is_delimiter(str[i + 1], charset))
			count++;
	}
	return (count);
}

int	next_index(char *str, char *charset, int flag)
{
	int	res;

	res = 0;
	while (is_delimiter(str[res], charset) == flag)
		res++;
	return (res);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (src[i])
			dest[i] = src[i];
		else
			dest[i] = 0;
	}
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		res_size;
	char	**res;
	int		i;
	int		offset;
	int		str_len;

	res_size = count_word(str, charset) + 1;
	res = (char **)malloc(sizeof(char *) * res_size);
	offset = 0;
	i = -1;
	while (++i < res_size - 1)
	{
		offset += next_index(str + offset, charset, 1);
		str_len = next_index(str + offset, charset, 0);
		res[i] = malloc(sizeof(char) * (str_len + 1));
		ft_strncpy(res[i], str + offset, str_len);
		res[i][str_len] = 0;
		offset += str_len;
	}
	res[res_size - 1] = 0;
	return (res);
}
//
//int main(void) {
//	char *str = "izcysMLh3HNJ2g45asonBIWx4VSMIorCnArqvW3";
//	char *charset = "TyirIBmN";
//
//	char **strs = ft_split(str, charset);
//	for (int i = 0; strs[i] != 0; i++) {
//		printf("strs[%d] = \"%s\"\n", i, strs[i]);
//		free(strs[i]);
//	}
//	free(strs);
//	return 0;
//}
