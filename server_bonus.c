/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:44:59 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/06/10 14:43:48 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_signal_handle(int sig, siginfo_t *info, void *pt)
{
	static char word;
	static int bit;

	(void)pt;
	if (sig == SIGUSR1)
		word = ((word << 1) | 1);
	else if (sig == SIGUSR2)
		word = (word << 1);
	bit++;
	if (bit == 8)
	{
		write(1, &word, 1);
		if (word == '\0')
			kill(info->si_pid, SIGUSR1);
		word = 0;
		bit = 0;
	}
}

int main()
{
	pid_t pid;
	struct sigaction sa;

	pid = getpid();
	printf("PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handle;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
