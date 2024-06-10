/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 23:41:04 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/06/10 16:05:47 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

size_t ft_strlen(const char *str);
int ft_atoi(const char *str);
void char_to_bits(int pid, char *str);
void ft_signal_handle(int sig, siginfo_t *info, void *pt);
void signal_handle(int sig);
void confirm_message(int signal);

#endif
