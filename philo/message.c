/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:39:27 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/09 17:11:40 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void display_message(char c, phil *phil)
{
	struct timeval end;
	if (gettimeofday(&end, NULL) == -1)
		error_exit(phil);
	long long int t_stamp = (end.tv_sec - phil->tv_start->tv_sec) * 1000;
	if (c == 'e')
		printf("%lld %d is eating\n", t_stamp, phil->phil_id);
	else if (c == 'f')
		printf("%lld %d has taken two forks\n", t_stamp, phil->phil_id);
	else if (c == 's')
		printf("%lld %d is sleeping\n", t_stamp, phil->phil_id);
	else if (c == 't')
		printf("%lld %d is thinking\n", t_stamp, phil->phil_id);
	else if (c == 'd')
		printf("%lld %d died\n", t_stamp, phil->phil_id);
}