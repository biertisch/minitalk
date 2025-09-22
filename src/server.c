/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:42:30 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/03 16:42:30 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*g_msg;

static void	mem_check(char *s)
{
	if (!s)
	{
		ft_printf("Error: memory allocation failed.\n");
		exit(1);
	}
}

static void	assemble_msg(char c)
{
	char	*tmp;
	char	append[2];

	append[0] = c;
	append[1] = '\0';
	if (!g_msg)
	{
		g_msg = ft_strdup(append);
		mem_check(g_msg);
	}
	else
	{
		tmp = g_msg;
		g_msg = ft_strjoin(tmp, append);
		free(tmp);
		mem_check(g_msg);
	}
	if (c == '\0')
	{
		ft_printf("%s\n", g_msg);
		free(g_msg);
		g_msg = NULL;
	}
}

static void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		assemble_msg(c);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
