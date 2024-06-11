/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 23:41:04 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/06/11 21:05:15 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	signal_handle(int sig);
void	confirm_message(int signal);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	char_to_bits(int pid, char *str);
void	ft_signal_handle(int sig, siginfo_t *info, void *pt);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
