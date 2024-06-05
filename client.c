/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:48:47 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/06/05 21:45:56 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_atoi(const char *str)
{
	int i;
	int result;
	int sign;

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

void char_to_bits(int pid, char *str)
{
	int i;
	int bits;

	i = 0;
	while (str[i] != '\0')
	{
		bits = 7;
		while (bits >= 0)
		{
			if (((str[i] >> bits ) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
			bits--;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int pid;

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
	char_to_bits(pid, av[2]);
	ft_strlen(av[2]);
	return (0);
}
