
#include "rush02.h"
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		tmp;
	int		count;
	char	*str;

	count = 0;
	tmp = nbr;
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	if (nbr == 0)
		count = 1;
	str = (char *)malloc(sizeof(char) * (count + 1));
	str[count] = 0;
	while (count--)
	{
		str[count] = '0' + nbr % 10;
		nbr /= 10;
	}
	return (str);
}
//
//#include <stdio.h>
//int main(void) {
//	for (int i = 0; i < 101; i++) {
//		printf("%s\n", ft_itoa(i));
//	}
//
//	return 0;
//}
