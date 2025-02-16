

char	*ft_strcpy(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s2[index] != '\0')
	{
		s1[index] = s2[index];
		index++;
	}
	s1[index] = '\0';
	return (s1);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[] = "Flavio";
	char str2[20];
	char str3[20];
	strcpy(str2, str1);
	ft_strcpy(str3, str1);
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return (0);
}
*/