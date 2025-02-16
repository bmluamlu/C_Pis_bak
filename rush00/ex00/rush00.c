
void	ft_putchar(char c);


void	print_line(char start_end, char middle, int width)
{
	int	column;

	
	ft_putchar(start_end);
	
	column = 1;
	
	while (column < width - 1)
	{
		ft_putchar(middle);
		column++;
	}
	
	if (width > 1)
	{
		ft_putchar(start_end);
	}
	
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	else
	{
		
		print_line('o', '-', x);
		row = 1;
		
		while (row < y - 1)
		{
			print_line('|', ' ', x);
			row++;
		}
	}
	
	if (y > 1)
	{
		print_line('o', '-', x);
	}
}
