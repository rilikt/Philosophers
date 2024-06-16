/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:23:56 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 16:45:26 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_to_bed(phil *phil)
{
	if (dead_check(phil) || full_check(phil))
	{
		return ;
		// pthread_mutex_unlock(&phil->mutex.fork);
		// pthread_mutex_unlock(&phil->next->mutex.fork);
	}
	display_message('s', phil);
	// pthread_mutex_unlock(&phil->mutex.fork);
	// pthread_mutex_unlock(&phil->next->mutex.fork);
	better_usleep(phil->sleep_time, phil);
	display_message('t', phil);
	eat(phil);
}
