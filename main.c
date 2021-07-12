/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:04:40 by kkalinic          #+#    #+#             */
/*   Updated: 2021/07/07 15:04:43 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*n_s;

	n_s = s;
	while (n)
	{
		*n_s = '\0';
		n_s++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;

	arr = malloc(size * nmemb);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid(), 10);
	if (!pid)
		exit(0);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	get_amount();
	while (1)
		usleep(10);
}
