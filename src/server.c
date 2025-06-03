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

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	
	return (0);
}


//process bits with handler function (sigaction())
//mask other signall using sigset_t mask, sigemptyset and sigaddset

//wait for signal (pause())

//reconstruct message - bit to chars (handler function) 
// BONUS handle unicode characters


//print message
//BONUS acknowledge message receipt by sending a signal to client