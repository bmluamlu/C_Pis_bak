void ft_putnbr(int nb);
void ft_putchar(char c);
void ft_putstr(char *str);
int *parse_input(char *str);
int validate_input(int argc, char **argv);
int check_double(int tab[10][10], int pos, int num, int flag);
int check_case(int tab[10][10], int pos, int entry[100], int flag);
#include <stdlib.h>
#include <stdio.h>

int solve(int tab[10][10], int entry[100], int pos, int flag)
{
	int size;

	if (pos == (flag * flag))
		return (1);
	size = 0;
	while (++size <= flag)
	{
		if (check_double(tab, pos, size, flag) == 0)
		{
			tab[(pos / flag)][(pos % flag)] = size;
			if (check_case(tab, pos, entry, flag) == 0)
			{
				if (solve(tab, entry, pos + 1, flag) == 1)
					return (1);
			}
			else
				tab[(pos / flag)][(pos % flag)] = 0;
		}
	}
	return (0);
}

void display_solution(int tab[10][10], int flag)
{
	int i;
	int j;

	i = -1;
	while (++i < flag)
	{
		j = -1;
		while (++j < flag)
		{
			ft_putnbr(tab[i][j]);
			if(j != (flag - 1))
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int main(int argc, char **argv)
{	
	int tab[10][10] = {
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		};
	int *entry;
	int flag;
	
	flag = validate_input(argc, argv);
	if (flag == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	entry = parse_input(argv[1]);
	printf("%d\n", *entry);

	if (solve(tab, entry, 0, flag) == 1)
		display_solution(tab, flag);
	else
		ft_putstr("Error\n");
	
	free(entry);
	return (0);
}