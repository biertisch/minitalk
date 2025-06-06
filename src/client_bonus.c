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
		bit++;
		usleep(500);
	}
}

static void	send_message(pid_t server_pid, char *message)
{
	unsigned int	i;

	i = 0;
	while (message[i])
	{
		send_bits(server_pid, message[i]);
		i++;
	}
	send_bits(server_pid, '\n');
	send_bits(server_pid, '\0');
	usleep(500);
}

static void	handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Message received.\n");
		exit(0);
	}
}

static void	signal_setup(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int argc, char **argv)
{
	pid_t			server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <server_pid> <message>\n");
		return (1);
	}
	signal_setup();
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 10 || kill(server_pid, 0) == -1)
	{
		ft_printf("Error: Invalid server PID.\n");
		return (1);
	}
	send_message(server_pid, argv[2]);
	return (0);
}
