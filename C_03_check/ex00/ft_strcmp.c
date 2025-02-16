
int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	count;

	count = 0;
	while ((s1[count] != '\0' || s2[count] != '\0') && s1[count] == s2[count])
	{
		count++;
	}
	return (s1[count] - s2[count]);
}


#include <stdio.h>
#include <string.h>

int	main()
{
	printf("%d", ft_strcmp("AAA", "AAA"));
	printf("\n%d", strcmp("AAA", "AAA"));
}

