/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 06:15:59 by anaji-el          #+#    #+#             */
/*   Updated: 2022/03/09 16:36:52 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void send_msg(int pid, char *str)
{
	int i;
	int j;
	
	i=0;
	
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] & 128 >> j) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(800);
		}
		i++;
	}
}
int main(int ac, char **av)
{
	int pid;
	if(ac != 3)
	{
		write(1,"INVALID ARGUMENT !", 19);
		exit(EXIT_FAILURE);
	}

	pid = atoi(av[1]);	
	if (pid <= 0)
	{
		write(1,"client:" "INVALID PID!",20);
	}
	send_msg(pid, av[2]);
}
