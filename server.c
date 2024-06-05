/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:38:49 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/06/05 21:02:46 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handle(int sig)
{
	static char word;
	static int bit;

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

int main()
{
	pid_t pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, signal_handle);
	signal(SIGUSR2, signal_handle);
	while (1)
		pause();
	return (0);
}
