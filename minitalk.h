/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:34:40 by llawrenc          #+#    #+#             */
/*   Updated: 2022/01/03 14:51:27 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./Libft/libft.h"
# include <signal.h>

void	output_pid(int pid);
void	output_sent_char(char *str);
void	send_signal(int pid, unsigned char ch);
void	output_str(int signal, siginfo_t *siginfo, void *context);

#endif
