/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 17:07:52 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_values(phil *one)
{
	one->phil_id = 1;
	one->phil_count = 5;
	one->dead = 0;
	one->full = 5;
	one->meal_count = 0;
	one->die_time = to_micro(500);
	one->eat_time = to_micro(200);
	one->sleep_time = to_micro(200);
	one->fork = 1;
	one->next = NULL;
	one->start_time = get_time();
	one->last_meal = get_time();
	one->ready = 0;
}

int	main(void)
{
	phil	*one;

	one = NULL;
	one = (phil *)malloc(sizeof(phil));
	init_values(one);
	create_list(one);
	// print_list(one);
	create_mutex(one);
	// set_time(one);
	inital_message(one->phil_count);
	create_threads(one);
	destroy_mutex(one);
	free_list(one);
	return (0);
}
