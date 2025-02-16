
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	while (b < nb && src[b] != '\0')
	{
		dest[a + b] = src[b];
		b++;
	}
	dest[a + b] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char src[30] = "Tokyo";
	char dest[30] = "42 ";
	char src2[30] = "Tokyo";
	char dest2[30] = "42 ";
	printf("%s", ft_strncat(dest, src, 1));
	printf("\n%s", strncat(dest2, src2, 1));
}
*/