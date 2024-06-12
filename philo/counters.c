/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:23:56 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/12 17:39:36 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void go_to_bed(phil *phil)
{
	if (dead_check(phil) || full_check(phil))
	{
		pthread_mutex_unlock(&phil->mutex.fork);
		pthread_mutex_unlock(&phil->next->mutex.fork);
		return;
	}
	display_message('s', phil);
	pthread_mutex_unlock(&phil->mutex.fork);
	pthread_mutex_unlock(&phil->next->mutex.fork);

	usleep(phil->sleep_time);

	display_message('t', phil);
	eat(phil);
}

void eat(phil *phil) // when does die_time reset (when he starts eating or when finished?)
{
	while (1 && phil->next)
	{	
		if (dead_check(phil) || full_check(phil))
			return;
		grab_forks(phil);
	}
	while(1)
	{
		if (dead_check(phil))
			return;
	}
}
