/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:24:13 by tcynthia          #+#    #+#             */
/*   Updated: 2021/10/04 20:24:15 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putnbr(int nbr)
{
	char	sym;

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	sym = nbr % 10 + '0';
	write(1, &sym, 1);
}

int	ft_binar(int full, int sig, int base)
{
	if (sig == 30)
		return (0);
	if (full == 0)
		return (1);
	while (full-- > 0)
		base /= 2;
	return (base);
}

void	ft_bit(int *bite, int sig, int i)
{
	int		full;

	full = i % 7;
	(*bite) += ft_binar(full, sig, 128);
	if (full == 0)
	{
		if ((char)(*bite) != '\0')
			write(1, (void *)bite, 1);
		else
			write(1, "\n", 1);
		(*bite) = 0;
	}
}

void	ft_receiver(int sig)
{
	static int	i;
	static int	l;

	i++;
	ft_bit(&l, sig, i);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_receiver);
	signal(SIGUSR2, ft_receiver);
	while (1)
		pause();
}
