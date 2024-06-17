/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:23:56 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 19:26:35 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_to_bed(t_phil *phil)
{
	if (dead_check(phil) || all_full(phil))
		return ;
	display_message('s', phil);
	better_usleep(phil->sleep_time, phil);
	display_message('t', phil);
	if ((phil->phil_count % 2) != 0)
		think_offset(phil);
	eat(phil);
}
