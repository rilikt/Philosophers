/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:39:27 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/12 16:31:18 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void display_message(char c, phil *phil)
{
	int end = get_time();
	int t_stamp = end - phil->start_time;
	// printf("start: %ld\n", phil->tv_start->tv_sec);

	// printf("ts: %d\n", t_stamp);
	if (c == 'd')
		printf("%d %d died\n", t_stamp, phil->phil_id);
	else if (dead_check(phil))
		return;
	else if (c == 'e')
		printf("%d %d is eating\n", t_stamp, phil->phil_id);
	else if (c == 'f')
		printf("%d %d has taken a fork\n", t_stamp, phil->phil_id);
	else if (c == 's')
		printf("%d %d is sleeping\n", t_stamp, phil->phil_id);
	else if (c == 't')
		printf("%d %d is thinking\n", t_stamp, phil->phil_id);
}
