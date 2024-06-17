/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:45:04 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 16:34:40 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_phil *phil)
{
	if (phil->next)
	{
		while (1)
		{
			if (!dead_check(phil) && !all_full(phil))
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

void	grab_forks(t_phil *phil)
{
	get_forks(phil);
	display_message('f', phil);
	display_message('f', phil);
	update_meal_time(phil);
	display_message('e', phil);
	better_usleep(phil->eat_time, phil);
	update_meal_count(phil);
	set_forks(phil);
	go_to_bed(phil);
}

void	get_forks(t_phil *phil)
{
	if (dead_check(phil) || all_full(phil))
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
}

void	set_forks(t_phil *phil)
{
	if (dead_check(phil) || all_full(phil))
	{
		pthread_mutex_unlock(&phil->mutex.fork);
		pthread_mutex_unlock(&phil->next->mutex.fork);
		return ;
	}
	if (!phil->fork && !phil->next->fork)
	{
		phil->fork = 1;
		phil->next->fork = 1;
	}
	pthread_mutex_unlock(&phil->mutex.fork);
	pthread_mutex_unlock(&phil->next->mutex.fork);
}
