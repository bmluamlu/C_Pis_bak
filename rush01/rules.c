int check_double(int tab[10][10], int pos, int num, int flag)
{
	int i;

	i = -1;
	while (++i < (pos / flag))
		if (tab[i][pos % flag] == num)
			return (1);
	i = -1;
	while (++i < (pos % flag))
		if (tab[pos / flag][i] == num)
			return (1);
	return (0);
}

int check_col_up(int tab[10][10], int pos, int entry[100], int flag)
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if ((pos / flag) == (flag - 1))
	{
		while (i < flag)
		{
			if (tab[i][(pos % flag)] > max)
			{
				max = tab[i][(pos % flag)];
				count++;
			}
			i++;
		}
		if (entry[(pos % flag)] != count)
			return (1);
	}
	return (0);
}

int check_row_right(int tab[10][10], int pos, int entry[100], int flag)
{
	int i;
	int max_size;
	int visible_towers;

	i = flag;
	max_size = 0;
	visible_towers = 0;
	if ((pos % flag) == (flag -1))
	{
		while (--i >= 0)
		{
			if (tab[(pos / flag)][i] > max_size)
			{
				max_size = tab[pos / flag][i];
				visible_towers++;
			}
		}
		if (entry[(flag * 3) + (pos / flag)] != visible_towers)
			return (1);
	}
	return (0);
}

int check_col_down(int tab[10][10], int pos, int entry[100],int flag)
{
	int i;
	int max;
	int count;

	i = flag - 1;
	max = 0;
	count = 0;
	if ((pos / flag) == (flag - 1))
	{
		while (i >= 0)
		{
			if (tab[i][(pos % flag)] > max)
			{
				max = tab[i][(pos % flag)];
				count++;
			}
			i--;
		}
		if (entry[flag + pos % flag] != count)
			return (1);
	}
	return (0);
}

int check_row_left(int tab[10][10], int pos, int entry[100],int flag)
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos % flag == flag - 1)
	{
		while (i < flag)
		{
			if (tab[pos / flag][i] > max)
			{
				max = tab[pos / flag][i];
				count++;
			}
			i++;
		}
		if (entry[(flag * 2) + pos / flag] != count)
			return (1);
	}
	return (0);
}

int check_case(int tab[10][10], int pos, int entry[100], int flag)
{
	if (check_row_left(tab, pos, entry, flag) == 1)
		return (1);
	if (check_row_right(tab, pos, entry, flag) == 1)
		return (1);
	if (check_col_down(tab, pos, entry, flag) == 1)
		return (1);
	if (check_col_up(tab, pos, entry, flag) == 1)
		return (1);
	return (0);
}