#include<stdlib.h>
#include"rush02.h"

char	*trim_key(char *str)
{
	char	*start;
	char	*end;
	char	*result;
	char	*p;

	start = str;
	end = str + ft_strlen(str);
	while (*start != '\0' && (is_space(*start)))
		start++;
	result = (char *)malloc(end - start + 1);
	if (result == NULL)
		return (NULL);
	p = result;
	while (start < end)
		*p++ = *start++;
	*p = '\0';
	return (result);
}

char	*trim_value(char *str)
{
	char	*start;
	char	*end;
	char	*result;
	char	*p;

	start = str;
	end = str + ft_strlen(str);
	while (*start != '\0' && is_space(*start))
		start++;
	result = (char *)malloc(end - start + 1);
	if (result == NULL)
		return (NULL);
	p = result;
	while (start < end)
		*p++ = *start++;
	*p = '\0';
	return (result);
}
