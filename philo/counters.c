/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:23:56 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 14:27:39 by timschmi         ###   ########.fr       */
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

	better_usleep(phil->sleep_time, phil);

	display_message('t', phil);
	eat(phil);
}

void eat(phil *phil) // when does die_time reset (when he starts eating or when finished?)
{
	if (phil->next)
	{
		while (1)
		{	
			if (!dead_check(phil) && !full_check(phil))
				grab_forks(phil);
			else
				return;
		}
	}
	else
	{
		while(!dead_check(phil))
			usleep(100);
	}
}
