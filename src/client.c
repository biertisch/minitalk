/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:42:33 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/03 16:42:33 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	send_bits(pid_t server_pid, char c)
{
	unsigned int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t			server_pid;
	unsigned int	i;
	
	if (argc != 3)
	{
		ft_printf("Usage: ./client <server_pid> <string>\n");
		return (1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_bits(server_pid, argv[2][i]);
		i++;
	}
	send_bits(server_pid, '\0');
	return (0);
}

//BONUS receive message receipt from server
//Create a stop condition