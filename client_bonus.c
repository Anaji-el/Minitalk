/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:04:59 by anaji-el          #+#    #+#             */
/*   Updated: 2022/03/15 16:45:44 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r);
}

void	send(char c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{	
		bit = (c >> i) & 1;
		kill(pid, SIGUSR1 + bit);
		usleep (500);
		i--;
	}
}

void	success(int sig)
{
	(void)sig;
	write(1, "MSG SENT SUCCESSFULLY\n", 22);
}

int	main(int ac, char **av)
{
	char	*s;
	int		pid;

	signal(SIGUSR1, success);
	if (ac != 3)
	{
		write(1, "error\n", 6);
		return (2);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "invalid pid\n", 12);
		exit(EXIT_FAILURE);
	}
	s = av[2];
	while (*s != '\0')
	{
		send(*s, pid);
		s++;
	}
	send(0, pid);
}
