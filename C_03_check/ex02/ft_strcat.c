
char	*ft_strcat(char *dest, char *src)
{
	int	a;
	int	b;

	a = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	b = 0;
	while (src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char src[] = "strcat.c";
	char dest[] = "42";
	char src2[] = "strcat.c";
	char dest2[] = "42";
	printf("%s", ft_strcat(dest, src));
	printf("\n%s", ft_strcat(dest2, src2));
}
*/