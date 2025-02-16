void ft_putnbr(int nb);
void ft_putchar(char c);
void ft_putstr(char *str);
int ft_atoi(char *str);
int ft_strlen(char *str);
int *get_numbers(char *str);
int check(int ac, char **av);
int check_double(int tab[4][4], int pos, int num);
int check_case(int tab[4][4], int pos, int entry[16]);
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// common.c

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_atoi(char *str)
{
	int i;
	int nbr;
	int nbrminus;

	i = 0;
	nbr = 0;
	nbrminus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			nbrminus++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	if (nbrminus % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

void ft_putnbr(int nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

// ---------------------------

// rules.c
/*
check_double関数は、4x4の整数型二次元配列tab内で特定の数値numが指定された位置posに置かれる際のルール違反をチェックする目的で使用されます。
具体的には、この関数は与えられた数値が同じ行または列に既に存在するかどうかを検証します。
ここで、posは0から15までの値を取り、4x4グリッド上の一次元的な位置を表します。
この関数は、ルール違反がある場合に1を、ない場合に0を返します。
*/
int check_double(int tab[4][4], int pos, int num)
{
	int i;

	i = -1;
	/*
	while (++i < pos / 4)ループを使用して、posが指し示す位置の行より前の行に対してチェックを行います。
	ここでpos / 4は、posが表す一次元的な位置を二次元グリッドの行のインデックスに変換します。pos % 4は、同じ列に対するチェックを行います。
	if (tab[i][pos % 4] == num)条件文で、もし現在チェックしている行の特定の列にnumと同じ値があれば、1を返して関数を終了します。
	これは、同じ列内で数字が重複してはならないルールを表します。
	*/
	while (++i < pos / 4)
		if (tab[i][pos % 4] == num)
			return (1);
	/*
	列のチェック:
	i = -1;でインデックスをリセットした後、while (++i < pos % 4)ループを使用して、posが指し示す列より前の列に対してチェックを行います。
	pos / 4は、チェックを行う行を指定し、pos % 4で得られた値は列のインデックスを進めるために使用します。
	if (tab[pos / 4][i] == num)条件文で、もし現在チェックしている列の特定の行にnumと同じ値があれば、1を返して関数を終了します。
	これは、同じ行内で数字が重複してはならないルールを表します。
	*/
	i = -1;
	while (++i < pos % 4)
		if (tab[pos / 4][i] == num)
			return (1);
	/*
	ルール違反なし:
	関数の最後にreturn (0);があり、これは与えられたnumが現在の位置posに置かれることがルールに違反しないことを意味します。
	*/
	return (0);
}

int check_col_up(int tab[4][4], int pos, int entry[16])
{
	int i; // ループのインデックス。
	int max; // 現在の最大のタワーの高さ。
	int count; // 見えるタワーの数。

	i = 0; // 最初からカウントを始める。
	max = 0; // 最大値を0に初期化。
	count = 0; // カウントを0に初期化。
	// このチェックは、最後の行に達した時のみ実行されます。
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			// 現在のタワーが前に見たタワーよりも高ければ、カウントを増やします。
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i++;
		}
		// 見えるタワーの数が条件と一致しなければ、1を返してエラーを示します。
		if (entry[pos % 4] != count)
			return (1);
	}
	return (0); // 一致すれば、0を返して成功を示します。
}


int check_row_right(int tab[4][4], int pos, int entry[16])
{
	int i; // ループのインデックス。
	int max_size; // 現在の最大のタワーの高さ。
	int visible_towers; // 見えるタワーの数。

	i = 4; // 最後からカウントを始める。
	max_size = 0; // 最大値を0に初期化。
	visible_towers = 0; // カウントを0に初期化。
	// このチェックは、行の最後の要素に達した時のみ実行されます。
	if (pos % 4 == 3)
	{
		while (--i >= 0)
		{
			// 現在のタワーが前に見たタワーよりも高ければ、カウントを増やします。
			if (tab[pos / 4][i] > max_size)
			{
				max_size = tab[pos / 4][i];
				visible_towers++;
			}
		}
		// 見えるタワーの数が条件と一致しなければ、1を返してエラーを示します。
		if (entry[12 + pos / 4] != visible_towers)
			return (1);
	}
	return (0); // 一致すれば、0を返して成功を示します。
}

int check_col_down(int tab[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = 3;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i--;
		}
		if (entry[4 + pos % 4] != count)
			return (1);
	}
	return (0);
}

int check_row_left(int tab[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (tab[pos / 4][i] > max)
			{
				max = tab[pos / 4][i];
				count++;
			}
			i++;
		}
		if (entry[8 + pos / 4] != count)
			return (1);
	}
	return (0);
}

/*
解法をチェックするための関数check_caseを示しています。
関数の目的は、現在配置されている数値が特定のルールに遵守しているかどうかを確認することです。
ここでのルールは、行と列の両方に関するものが考慮されています。
tabは4x4の整数配列で、パズルの現在の状態（数値の配置）を表しています。
posは、現在注目しているセルの位置を示すインデックスです。この位置は0から15までの値を取り、パズル盤の左上から右下への線形なインデックスとして解釈されます。
entryは、各行、各列に関するルールや条件を示す16要素の整数配列です。これらのルールは、パズルの特定の種類によって異なりますが、一般的には、各行や列から見える数値の数、またはその他の特定の制約を指定するために使用されます。
*/
int check_case(int tab[4][4], int pos, int entry[16])
{
	if (check_row_left(tab, pos, entry) == 1)
		return (1);
	if (check_row_right(tab, pos, entry) == 1)
		return (1);
	if (check_col_down(tab, pos, entry) == 1)
		return (1);
	if (check_col_up(tab, pos, entry) == 1)
		return (1);
	return (0);
}

// -------------------------

// parsing.c

int check(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (ft_strlen(av[1]) != 31)
		return (1);
	return (0);
}

int *get_numbers(char *str)
{
    int i; // インデックス用の変数iを宣言します。これは文字列の現在位置を追跡するために使用されます。
    int j; // インデックス用の変数jを宣言します。これは数値の配列の現在位置を追跡するために使用されます。
    int *tab; // 整数の配列を指すポインタtabを宣言します。これは、見つかった数値を格納するために使用されます。

    // mallocを使用して16個の整数を格納できる配列を動的に割り当てます。
    // sizeof(int) * 16は、16個の整数分のメモリサイズを計算します。
    // 割り当てが失敗した場合（mallocがNULLを返した場合）、関数は0を返して終了します。
	if (!(tab = malloc(sizeof(int) * 16)))
		return (0);
    i = -1; // iを-1に初期化します。これは、whileループ内での先行インクリメント(++i)を使用するためです。
    j = 0;  // jを0に初期化します。これは、最初の数値を配列の最初の位置に格納するためです。
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
		{
			// str + iは現在の数字の文字から始まる部分文字列のアドレスを指します。
            // ft_atoiはこの文字列を整数に変換し、その結果をtab[j]に代入します。
            // jは次の空の位置を指すようにインクリメントされます。}
			tab[j++] = ft_atoi(str + i);
		}
	// 数値が格納された整数の配列へのポインタを返します。
	return (tab);
}

// --------------------------

// main.c
/*
パラメータ
int tab[4][4]: 現在のパズルの状態を保持する4x4の整数型2次元配列です。各要素は、特定のマスに配置された数字（またはまだ数字が割り当てられていない場合は0）を表します。
int entry[16]: パズルの初期条件または制約を表す、16要素の整数配列です。この配列の内容は関数内では直接使用されていませんが、check_case関数に渡され、そこで現在の配置がパズルのルールに適合しているかを検証するのに使われると推測されます。
int pos: 現在処理中のマスの位置を示す整数です。0から始まり、15（4x4グリッドの最後のマス）までの値を取り得ます。
*/
int solve(int tab[4][4], int entry[16], int pos)
{
	int size;

	// 終了条件: if (pos == 16)は、全てのマスを処理し終えたことを意味します。この場合、関数は1を返して成功を示します。
	if (pos == 16)
		return (1);
	// サイズの初期化: size = 0;では、次に試すべき数字のサイズを0に初期化します。
	size = 0;
	// 数字の配置試行: while (++size <= 4)ループは、1から4までの各数字を現在の位置に配置してみます。
	while (++size <= 4)
	{
		/*
		重複チェック: if (check_double(tab, pos, size) == 0)では、check_double関数を使って、
		現在試している数字（size）が現在の位置（pos）に配置してもルールに違反しないかをチェックします。違反しない場合に次へ進みます。
		*/
		if (check_double(tab, pos, size) == 0)
		{
			// 数字の配置: tab[pos / 4][pos % 4] = size;で、条件を満たす数字をグリッドに配置します。
			tab[pos / 4][pos % 4] = size;
			/*
			配置後のチェック: if (check_case(tab, pos, entry) == 0)では、check_case関数を使用して、
			新しい数字を配置した後のグリッドがパズルのルールに合致しているかをチェックします。
			*/
			if (check_case(tab, pos, entry) == 0)
			{
				/*
				次の可能性の検証: if (solve(tab, entry, pos + 1) == 1)は、再帰的にsolve関数を呼び出して、次のマスに対して解を試みます。
				この再帰呼び出しが成功すれば、関数は1を返して成功を示します。
				*/
				if (solve(tab, entry, pos + 1) == 1)
					return (1);
			}
			else
			/*
			バックトラック: else tab[pos / 4][pos % 4] = 0;では、現在の配置が最終的に問題を解決しない場合、
			その位置を0に戻して別の数字を試す準備をします（バックトラック）。
			*/
				tab[pos / 4][pos % 4] = 0;
		}
	}
	// 解が見つからない: ループが終了し、有効な解が見つからなかった場合、関数は0を返して失敗を示します。
	return (0);
}


void display_solution(int tab[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(tab[i][j]);
			if(j != 3)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int main(int ac, char **av)
{	

	int tab[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *entry;

	if (check(ac, av) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	entry = get_numbers(av[1]);

	if (solve(tab, entry, 0) == 1)
		display_solution(tab);
	else
		ft_putstr("Error\n");
	return (0);
}

// ----------------------------