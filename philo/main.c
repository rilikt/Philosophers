/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/05 17:04:51 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_thread(void *arg)
{
	printf("entered\n");
	
	phil *one = (phil *)arg;
	printf("phil: %d\n", one->phil_count);

	pthread_exit(NULL);
}

void init_values(phil *one)
{
	one->phil_count = 4;
	one->die_time = 120;
	one->eat_time = 10;
	one->sleep_time = 60;
}

int main(void)
{
	phil *one;
	pthread_t tid;

	init_values(one);
	
	while (one->phil_count)
	{
		printf("entered\n");
		pthread_create(&tid, NULL, philo_thread, one);
		pthread_join(tid, NULL);
		one->phil_count--;
	}
	return (0);
}