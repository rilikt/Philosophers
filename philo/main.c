/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/10 13:32:18 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_thread(void *arg)
{
	phil *one = (phil *)arg;
	// printf("-- %d joined the table --\n", one->phil_id);
	display_message('t', one);
	while (1)
	{
		if (one->next && (one->fork && one->next->fork))
			eat(one);
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
			if ((get_time(one) - temp->last_meal) > die_time)
			{
				display_message('d', temp);
				printf("last meal: %d\n", temp->last_meal);
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

	int death = 1200;
	one->die_time = to_micro(death);
	one->reset_d_time = to_micro(death);
	one->eat_time = to_micro(300);
	one->sleep_time = to_micro(500);

	one->fork = 1;
	one->next = NULL;
	if (gettimeofday(one->tv_start, NULL) == -1)
		error_exit(one);
	one->last_meal = get_time(one);
}

int main(void)
{
	phil *one;

	init_values(one);

	create_list(one);
	print_list(one);
	

	int count = one->phil_count;
	pthread_t *tid = malloc(count+1 * sizeof(pthread_t));
	phil *temp = one;
	
	
	int i = 0;
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
