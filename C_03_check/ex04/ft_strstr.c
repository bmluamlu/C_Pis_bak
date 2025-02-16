
char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (to_find[b] == '\0')
		return (str);
	while (str[a] != '\0')
	{
		while (str[a + b] == to_find[b] && str[a + b] != '\0')
			b++;
		if (to_find[b] == '\0')
			return (str + a);
		a++;
		b = 0;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "42 Tokyo Piscine C03 ft_strstr.c!";
	char find[] = "Piscine";
	printf("%s", ft_strstr(str, find));
	printf("\n%s", strstr(str, find));
}
*/