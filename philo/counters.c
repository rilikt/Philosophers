/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:23:56 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/07 17:23:11 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_forks(phil *phil)
{
	if (phil->fork && phil->next->fork)
	{
		phil->fork = 0;
		phil->next->fork = 0;
	}
	else if (!phil->fork && !phil->next->fork)
	{
		phil->fork = 1;
		phil->next->fork = 1;
	}
}

void reset_death(phil *phil)
{
	static int die_time = 12000000;
	phil->die_time = (int)die_time;
}

void go_to_bed(phil *phil) // also count die_time
{
	int s_time = phil->sleep_time;
	printf("Phil %d went to bed\n", phil->phil_id);
	while (s_time)
	{
		die_counter(phil);
		usleep(1);
		s_time--;
		if (!phil->die_time)
			return;
	}
	printf("Phil %d is thinking\n", phil->phil_id);
}

void eat(phil *phil) // when does die_time reset (when he starts eating or when finished?)
{
	int e_time = phil->eat_time;
	set_forks(phil);
	printf("Phil %d just picked up two forks\n", phil->phil_id);
	reset_death(phil);
	printf("Phil %d started eating\n", phil->phil_id);
	while (e_time)
	{
		die_counter(phil);
		usleep(1);
		e_time--;
		if (!phil->die_time)
			return;
	}
	set_forks(phil);
	printf("Phil %d just layed down two forks\n", phil->phil_id);
	go_to_bed(phil);
}

void die_counter(phil *phil)
{
	usleep(1);
	if (phil->die_time != 0)
		phil->die_time--;
}