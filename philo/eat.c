/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:45:04 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 15:25:49 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(phil *phil)
{
	if (phil->next)
	{
		while (1)
		{
			if (!dead_check(phil) && !full_check(phil))
				grab_forks(phil);
			else
				return ;
		}
	}
	else
	{
		while (!dead_check(phil))
			usleep(100);
	}
}

void	grab_forks(phil *phil)
{
	get_forks(phil);
	display_message('f', phil);
	display_message('f', phil);
	update_meal_count_time(phil);
	display_message('e', phil);
	better_usleep(phil->eat_time, phil);
	set_forks(phil);
	go_to_bed(phil);
}

void	get_forks(phil *phil)
{
	if (dead_check(phil))
		return ;
	if ((phil->phil_id % 2) == 0)
	{
		pthread_mutex_lock(&phil->next->mutex.fork);
		pthread_mutex_lock(&phil->mutex.fork);
	}
	else
	{
		pthread_mutex_lock(&phil->mutex.fork);
		pthread_mutex_lock(&phil->next->mutex.fork);
	}
	if (phil->fork && phil->next->fork)
	{
		phil->fork = 0;
		phil->next->fork = 0;
	}
	else
	{
		pthread_mutex_unlock(&phil->mutex.fork);
		pthread_mutex_unlock(&phil->next->mutex.fork);
		eat(phil);
	}
}

void	set_forks(phil *phil) // maybe unlock forks here instead of sleep
{
	if (dead_check(phil))
		return ;
	if (!phil->fork && !phil->next->fork)
	{
		phil->fork = 1;
		phil->next->fork = 1;
	}
}
