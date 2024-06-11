/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:38:49 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/06/11 20:32:15 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	n = n % 10 + '0';
	ft_putchar_fd(n, fd);
}

void	signal_handle(int sig)
{
	static char	word;
	static int	bit;

	if (sig == SIGUSR1)
		word = ((word << 1) | 1);
	else if (sig == SIGUSR2)
		word = (word << 1);
	bit++;
	if (bit == 8)
	{
		write(1, &word, 1);
		word = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handle);
	signal(SIGUSR2, signal_handle);
	while (1)
		pause();
	return (0);
}
