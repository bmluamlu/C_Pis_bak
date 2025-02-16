
#ifndef RUSH02_H
# define RUSH02_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

int		is_space(char c);
void	ft_putstr(char *str);
char	*ft_itoa(int nbr);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	**ft_split(char *str, char *charset);
char	*ft_strjoin(int size, char **strs, char *sep);
int		validate_input(int argc, char **argv);
char	*trim_key(char *str);
char	*trim_value(char *str);
char	*file_content(char *path);
t_dict	*sep_key_value(char **strs);
int		dict_error_check(t_dict *dict);
void	print_one_digit(char *n, t_dict *dict);
void	print_two_digit(char *n, t_dict *dict);
void	print_three_digit(char *n, t_dict *dict);
void	print_digits(char *n, t_dict *dict);

#endif
