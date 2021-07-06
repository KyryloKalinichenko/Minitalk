#include "head.h"

int	ft_isotherwhitespace(char c)
{
	return (c == '\v' || c == '\f' || c == '\r');
}

int	ft_isstrwhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	ft_iswhitespace(char c)
{
	return (ft_isstrwhitespace(c) || ft_isotherwhitespace(c));
}

int	ft_atoi(const char *str)
{
	int						i;
	long long int	nbr;
	long long int			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (nbr < 0 || i > 19)
	{
		if (sign > 0)
			return (-1);
	}
	return (nbr * sign);
}

int ft_strlen(char *s)
{
    int i;

    i = 0;
	if (!s)
		return (0);
    while(s[++i])
        ;
    return (i);
}