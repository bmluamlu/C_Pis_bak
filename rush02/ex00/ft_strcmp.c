
int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (1)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == 0)
			break ;
		i++;
	}
	return (0);
}
