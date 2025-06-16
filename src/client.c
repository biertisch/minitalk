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

volatile sig_atomic_t	g_ack = 0;

static void	send_bits(pid_t server_pid, unsigned char c)
{
	unsigned int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack = 0;
		if (c & (1 << bit))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		bit++;
		while (!g_ack)
			usleep(10);
	}
}

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
}

static void	signal_setup(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
}

int	main(int argc, char **argv)
{
	pid_t			server_pid;
	unsigned char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <server_pid> <message>\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || kill(server_pid, 0) == -1)
	{
		ft_printf("Error: Invalid server PID.\n");
		return (1);
	}
	signal_setup();
	message = (unsigned char *)argv[2];
	while (*message)
		send_bits(server_pid, *message++);
	send_bits(server_pid, '\0');
	return (0);
}
