/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:23:56 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/11 19:00:35 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void go_to_bed(phil *phil)
{
	display_message('s', phil);

	usleep(phil->sleep_time);

	display_message('t', phil);
	eat(phil);
}

void eat(phil *phil) // when does die_time reset (when he starts eating or when finished?)
{
	while (1 && phil->next)
	{
		grab_forks(phil);
	}
}
