/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/07 17:29:05 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_thread(void *arg)
{
	phil *one = (phil *)arg;
	printf("Thread for phil_id: %d created.\n", one->phil_id);
	while (one->die_time)
	{
		die_counter(one);
		if (one->fork && one->next->fork)
			eat(one);
	}
	printf("Phil %d has died :'(\n", one->phil_id);
	pthread_exit(NULL);
}

void init_values(phil *one)
{
	one->phil_id = 1;
	one->phil_count = 5;
	one->die_time = 1200000;
	one->eat_time = 1000000;
	one->sleep_time = 1000000;
	one->fork = 1;
	one->next = NULL;
}

int main(void)
{
	phil *one;

	init_values(one);
	create_list(one);
	print_list(one);
	int count = one->phil_count;
	
	pthread_t *tid = malloc(count * sizeof(pthread_t));

	phil *temp = one;
	int i = 0;
	while (i < count)
	{
		pthread_create(&tid[i], NULL, philo_thread, temp);
		usleep(42);
		i++;
		temp = temp->next;
	}
	i = 0;
	while (i < count)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (0);
}