/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/09 17:11:32 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_thread(void *arg)
{
	phil *one = (phil *)arg;
	printf("-- Thread for phil_id: %d created. --\n", one->phil_id);
	while (one->die_time)
	{
		die_counter(one);
		if (one->next && (one->fork && one->next->fork))
			eat(one);
	}
	display_message('d', one);
	pthread_exit(NULL);
}

void init_values(phil *one)
{
	one->phil_id = 1;
	one->phil_count = 5;
	one->die_time = to_micro(600);
	one->eat_time = to_micro(400);
	one->sleep_time = to_micro(400);
	one->fork = 1;
	one->next = NULL;
	if (gettimeofday(one->tv_start, NULL) == -1)
		error_exit(one);
}

int main(void)
{
	phil *one;


	init_values(one);
	printf("time: %ld\n", one->tv_start->tv_sec);
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