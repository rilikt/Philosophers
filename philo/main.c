/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/11 18:50:58 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_thread(void *arg) // find a better way to sync all threads so they start at the time when every thread is created
{
	phil *one = (phil *)arg;
	display_message('t', one);
	usleep(100);
	eat(one);
	while(1)
	{

	}
	display_message('d', one);
	pthread_exit(NULL);
}

void *watch_time(void *arg)
{
	phil *one = (phil *)arg;
	int i;
	int count = one->phil_count;
	int die_time = one->die_time / 1000;
	phil *temp;
	while (1)
	{
		i = 0;
		temp = one;
		while (i < count)
		{
			if ((get_time() - temp->last_meal) > die_time)
			{
				display_message('d', temp);
				// printf("last meal: %d\n", temp->last_meal);
				exit(1);
			}
			// printf("%d %d\n", get_time(one) - temp->last_meal, die_time);
			temp = temp->next;
			i++;
			usleep(1000);
		}
	}
}

void init_values(phil *one)
{
	one->phil_id = 1;
	one->phil_count = 5;

	one->die_time = to_micro(1200);
	one->eat_time = to_micro(400);
	one->sleep_time = to_micro(400);

	one->fork = 1;
	one->next = NULL;
	one->start_time = get_time();
	one->last_meal = get_time();
}

int main(void)
{
	phil *one = NULL;
	one = (phil*)malloc(sizeof(phil));
	init_values(one);



	create_list(one);
	print_list(one);
	

	int count = one->phil_count;
	pthread_t *tid = malloc(count+1 * sizeof(pthread_t));
	phil *temp = one;
	
	
	int i = 0;

	while (i < count)
	{
		pthread_mutex_init(&temp->mutex.fork, NULL);
		i++;
		temp = temp->next;
	}
	i = 0;
	temp = one;
	while (i < count)
	{
		pthread_create(&tid[i], NULL, philo_thread, temp);
		usleep(10);
		i++;
		temp = temp->next;
	}
	pthread_create(&tid[count], NULL, watch_time, one);

	i = 0;
	while (i <= count)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (0);
}
