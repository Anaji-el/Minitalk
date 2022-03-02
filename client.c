/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 06:15:59 by anaji-el          #+#    #+#             */
/*   Updated: 2022/03/02 16:32:56 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	send_char(int pid, char c)
{
	int	i;
	int bit;
	
	i = 8
	while(i++)
	{
		bit = (c << i & 128)
		if( bit == 0)
			kill(pid,SIGUSR2);
		if(bit == 1)
			kill(pid,SIGUSR1);
	
	}
}
void	send_string(int pid, char *str)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
}