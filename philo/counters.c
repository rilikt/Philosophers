/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:23:56 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/09 16:53:00 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void reset_death(phil *phil)
{
	static int die_time = 12000000;
	phil->die_time = (int)die_time;
}

void go_to_bed(phil *phil) // also count die_time
{
	int s_time = phil->sleep_time;
	display_message('s', phil);
	while (s_time)
	{
		die_counter(phil);
		usleep(1);
		s_time--;
		if (!phil->die_time)
			return;
	}
	display_message('t', phil);
}

void eat(phil *phil) // when does die_time reset (when he starts eating or when finished?)
{
	int e_time = phil->eat_time;
	set_forks(phil);
	reset_death(phil);
	display_message('f', phil);
	display_message('e', phil);
	while (e_time)
	{
		die_counter(phil);
		usleep(1);
		e_time--;
		if (!phil->die_time)
			return;
	}
	set_forks(phil);
	go_to_bed(phil);
}

void die_counter(phil *phil)
{
	usleep(1);
	if (phil->die_time != 0)
		phil->die_time--;
}