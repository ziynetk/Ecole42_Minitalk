/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkusasla <zkusasla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:37:10 by zkusasla          #+#    #+#             */
/*   Updated: 2023/01/16 21:30:20 by zkusasla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *s)
{
	int	i;

	i = 0;
	while (*s)
		i = (i * 10) + (*s++ - '0');
	return (i);
}

void	ft_take(pid_t pid, char c)
{
	int				n;
	int				bit;

	bit = 8;
	n = 128;
	while (bit--)
	{
		if (c / n)
		{
			c -= n;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(150);
		n /= 2;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*msg;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		msg = av[2];
		while (msg[i])
		{
			ft_take(pid, msg[i]);
			i++;
		}
	}
	else
		return (0);
}
