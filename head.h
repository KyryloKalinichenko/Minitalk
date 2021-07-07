#ifndef HEAD_H
# define HEAD_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

typedef struct s_list
{
	int		cl_pid;
	int		cnt;
	char	*str;
	int		len;
	int		tmp;
}					t_list;

char			*ft_itoa(long long k, int base);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_strlen(char *s);
void			int_read(int signum);
void			get_amount(void);
void			*ft_calloc(size_t nmemb, size_t size);

#endif
