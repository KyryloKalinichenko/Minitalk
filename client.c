/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:55:16 by kkalinic          #+#    #+#             */
/*   Updated: 2021/07/07 14:03:27 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**    SIGUSR2 == 1
**    SIGUSR1 == 0
*/

int	get_pid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			exit(0);
	}
	return (ft_atoi(str));
}

void	int_to_by(int i, int pid)
{
	int	cnt;

	cnt = 31;
	while (cnt > -1)
	{
		if (((i >> cnt) & 1))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
		cnt--;
	}
}

void	char_to_by(unsigned char i, int pid)
{
	int	cnt;

	cnt = 7;
	while (cnt > -1)
	{
		if (((i >> cnt) & 1))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
		cnt--;
	}
}

void	send_str(char *str, int pid)
{
	int	i;
	int	b;

	i = -1;
	b = 0;
	while (str[++i])
		char_to_by(str[i], pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3 || argc > 3 || !argv[2] || !ft_strlen(argv[2]))
		exit(0);
	pid = get_pid(argv[1]);
	int_to_by(getpid(), pid);
	int_to_by(ft_strlen(argv[2]) * sizeof(*argv[2]), pid);
	send_str(argv[2], pid);
	return (0);
}
