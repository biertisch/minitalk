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

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	
	if (argc != 3)
	{
		ft_printf("Usage: ./client <server_pid> <string>\n");
		return (-1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);

	return (0);
}

//convert message into bits

//send signal (kill)

//give time for server to process (usleep(100))

//BONUS receive message receipt from server