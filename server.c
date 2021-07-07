/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:25:34 by kkalinic          #+#    #+#             */
/*   Updated: 2021/07/07 14:59:31 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list	g_all;

void	for_one(void)
{
	g_all.str[0] = g_all.tmp;
	g_all.tmp = 0;
	if (ft_strlen(g_all.str) == g_all.len)
	{
		write(1, g_all.str, g_all.len);
		write(1, "\n", 1);
		free(g_all.str);
		g_all.cnt = 0;
		g_all.len = 0;
		g_all.cl_pid = 0;
		g_all.tmp = 0;
	}
}

void	for_other(int ind)
{
	g_all.str[ind - 1] = g_all.tmp;
	g_all.tmp = 0;
	if (ft_strlen(g_all.str) == g_all.len)
	{
		write(1, g_all.str, g_all.len);
		write(1, "\n", 1);
		free(g_all.str);
		g_all.cnt = 0;
		g_all.len = 0;
		g_all.cl_pid = 0;
		g_all.tmp = 0;
	}
}

void	read_str(int signum, int ind)
{
	ind = (g_all.cnt - 64) / 32;
	if (signum == 30)
		g_all.tmp = g_all.tmp << 1;
	else if (signum == 31)
		g_all.tmp = (g_all.tmp << 1) + 1;
	if (!((g_all.cnt - 64) % 32) && g_all.len != 1)
		for_other(ind);
	else if (g_all.len == 1 && g_all.cnt - 64 == 32)
		for_one();
}

void	int_read(int signum)
{
	int	ind;

	++g_all.cnt;
	ind = 0;
	if (g_all.cnt <= 32 && signum == 30)
		g_all.cl_pid = g_all.cl_pid << 1;
	else if (g_all.cnt <= 32 && signum == 31)
		g_all.cl_pid = (g_all.cl_pid << 1) + 1;
	else if (g_all.cnt > 32 && signum == 30 && g_all.cnt <= 64)
		g_all.len = g_all.len << 1;
	else if (g_all.cnt > 32 && signum == 31 && g_all.cnt <= 64)
		g_all.len = (g_all.len << 1) + 1;
	if (g_all.cnt == 64)
		g_all.str = ft_calloc(sizeof(char), g_all.len + 1);
	if (g_all.cnt > 64)
		read_str(signum, ind);
}

void	get_amount(void)
{
	signal(SIGUSR1, int_read);
	signal(SIGUSR2, int_read);
}
