/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:39:27 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/10 13:27:03 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void display_message(char c, phil *phil)
{
	struct timeval end;
	if (gettimeofday(&end, NULL) == -1)
		error_exit(phil);
	int u_sec = end.tv_usec - phil->tv_start->tv_usec;
	int sec = end.tv_sec - phil->tv_start->tv_sec;
	int t_stamp = ((sec * 1000) + (u_sec / 1000));
	if (c == 'e')
		printf("%d %d is eating\n", t_stamp, phil->phil_id);
	else if (c == 'f')
		printf("%d %d has taken a fork\n", t_stamp, phil->phil_id);
	else if (c == 's')
		printf("%d %d is sleeping\n", t_stamp, phil->phil_id);
	else if (c == 't')
		printf("%d %d is thinking\n", t_stamp, phil->phil_id);
	else if (c == 'd')
		printf("%d %d died\n", t_stamp, phil->phil_id);
}