/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/07 16:00:37 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_thread(void *arg)
{
	phil *one = (phil *)arg;
	printf("Thread for phil_id: %d created.\n", one->phil_id);`

	pthread_exit(NULL);
}

void init_values(phil *one)
{
	one->phil_id = 1;
	one->phil_count = 5;
	one->die_time = 120;
	one->eat_time = 10;
	one->sleep_time = 60;
	one->fork = 0;
	one->next = NULL;
}

int main(void)
{
	phil *one;
	pthread_t tid;

	init_values(one);
	create_list(one);
	print_list(one);
	

	int count = one->phil_count;
	phil *temp = one;
	while (count)
	{
		pthread_create(&tid, NULL, philo_thread, temp);
		pthread_join(tid, NULL);
		count--;
		temp = temp->next;
	}
	return (0);
}