/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 06:16:33 by anaji-el          #+#    #+#             */
/*   Updated: 2022/03/08 17:13:49 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int signum, siginfo_t *info, void *arg)
{
	
	static char printed = 0b11111111;
	static int shifter;
	static int client_pid;
   (void) arg;
	if (client_pid != 0 && client_pid != info->si_pid)
	{
		write (1, "\n", 1);
		printed = 0b11111111;
		shifter = 0;
	}
   	if (signum == SIGUSR1)
		printed = printed | 128 >> shifter;
	else if (signum == SIGUSR2)
		printed = printed ^ 128 >> shifter;
	shifter++;
	if(shifter == 8)
	{
		write(1, &printed, 1);
		printed = 0b11111111;
		shifter = 0;
	}
	client_pid = info->si_pid;
}

int	main()
{
	 struct sigaction avd;
   pid_t	pid;
   pid = getpid();
  
   printf("PID: %d\n", pid);
   avd.sa_sigaction = handler;
   
	avd.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &avd, NULL);
	sigaction(SIGUSR2, &avd, NULL);
	while (1)
   		pause();
	return (0);
}