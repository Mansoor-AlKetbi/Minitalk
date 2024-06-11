/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:45:22 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/06/11 20:05:07 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			result = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

void	confirm_message(int signal)
{
	if (signal == SIGUSR1)
		write(1, "The signal has been recieved,", 28);
	exit(1);
}

void	char_to_bits(int pid, char *str)
{
	int	i;
	int	bits;

	i = 0;
	while (1)
	{
		bits = 7;
		while (bits >= 0)
		{
			if (((str[i] >> bits) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
			bits--;
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	if (ac != 3)
		write(1, "Insufficient amount of arguments\n", 33);
	pid = ft_atoi(av[1]);
	if (pid == 0)
		write(1, "The pid is incorrect", 20);
	if (ft_strlen(av[2]) == 0)
	{
		write(1, "Message is empty\n", 17);
		return (1);
	}
	sa.sa_handler = confirm_message;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	char_to_bits(pid, av[2]);
	pause();
	return (0);
}
