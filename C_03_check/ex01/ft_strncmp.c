
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (count < n && (s1[count] != '\0' || s2[count] != '\0'))
	{
		if (s1[count] > s2[count])
			return (1);
		else if (s1[count] < s2[count])
			return (-1);
		count++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	printf("%d", ft_strncmp("Hello", "", 5));
	printf("\n%d", strncmp("Hello", "", 5));
	printf("%c", '\n');
	printf("%d", ft_strncmp("Hello", "HelloWorld", 8));
	printf("\n%d", strncmp("Hello", "HelloWorld", 8));
}
*/