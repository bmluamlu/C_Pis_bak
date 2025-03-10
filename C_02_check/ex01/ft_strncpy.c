

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char src[] = "Hello";
	char dest[] = "Wor-ld";

	printf("%s", ft_strncpy(dest, src, 3));
	printf("\n%s", strncpy(dest, src, 3));
	printf("\n%s", ft_strncpy(dest, src, 7));
}
*/