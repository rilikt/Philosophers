/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:23:56 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/10 13:27:34 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void go_to_bed(phil *phil) // also count die_time
{
	int s_time = phil->sleep_time;
	display_message('s', phil);

	usleep(s_time);

	display_message('t', phil);
}

void eat(phil *phil) // when does die_time reset (when he starts eating or when finished?)
{
	int e_time = phil->eat_time;
	set_forks(phil);
	display_message('f', phil);
	display_message('f', phil);
	display_message('e', phil);
	phil->last_meal = get_time(phil);

	usleep(e_time);

	set_forks(phil);
	go_to_bed(phil);
}
