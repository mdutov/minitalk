/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:23:57 by tcynthia          #+#    #+#             */
/*   Updated: 2021/10/04 20:23:59 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	slen(const char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		;
	return (i);
}

int	miniatoi(char *s)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		ret += s[i] - '0';
		if (s[++i])
			ret *= 10;
	}
	return (ret);
}

void	ft_bin(int pid, int asc, int base)
{
	while (base != 0)
	{
		if (asc < base)
		{
			base /= 2;
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else
		{
			asc -= base;
			kill(pid, SIGUSR2);
			base = base / 2;
			usleep(100);
		}
	}
}

void	ft_binchar(char *s, int pid, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_bin(pid, (int)s[i], 64);
	ft_bin(pid, 0, 64);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		write(1, "minitalk: bad arguments\n",
			slen("minitalk: bad arguments\n"));
		return (0);
	}
	pid = miniatoi(argv[1]);
	if (pid < 0)
	{
		write(1, "minitalk: invalid server's PID\n",
			slen("minitalk: invalid server's PID\n"));
		return (0);
	}
	ft_binchar(argv[2], pid, slen(argv[2]));
}
