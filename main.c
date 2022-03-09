/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:11:52 by anaji-el          #+#    #+#             */
/*   Updated: 2022/03/05 16:52:40 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	yoink(int num) {
	write(1, "We stand with Ukrain\n", 22);
}

int		main()
{
	signal(SIGINT, yoink);
	signal(SIGTERM, yoink);
	while (1)
	{
		write(1, "Putin\n", 7);
		sleep(1);
	}
	
	return (0);
} 