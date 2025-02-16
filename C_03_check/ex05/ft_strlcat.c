
int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	dlen;
	unsigned int	slen;

	a = 0;
	b = 0;
	while (dest[b] != '\0')
	{
		b++;
	}
	dlen = b;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (size + dlen);
	while (src[a] != '\0' && a < size - dlen - 1)
	{
		dest[b] = src[a];
		a++;
		b++;
	}
	dest[b] = '\0';
	return (dlen + slen);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[40] = "42 Tokyo";
	char	dest[40] = "Piscine aaa";
	char	src2[40] = "42 Tokyo";
	char	dest2[40] = "Piscine aaa";
	printf("%i \n", ft_strlcat(dest, src, 40));
	printf("%s \n", dest);
	printf("%lu \n", strlcat(dest2, src2, 40));
	printf("%s \n", dest2);
}
*/