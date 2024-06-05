/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 23:41:04 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/06/05 19:24:17 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *str);
int	ft_atoi(const char *str);
void	char_to_bits(int pid, char *str);
void	signal_handle(int sig);

#endif
