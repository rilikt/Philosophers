/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:57:37 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 15:27:57 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *arg) // find a better way to sync all threads so they start at the time when every thread is created
{
	phil *one = (phil *)arg;
	inital_message(one);
	one->ready = 1;
	while (!threads_ready(one))
		usleep(100);
	if ((one->phil_id % 2) != 0)
		better_usleep((one->eat_time / 2), one);
	eat(one);
	if (full_check(one))
		display_message('t', one);
	pthread_exit(NULL);
}

void	*watch_time(void *arg)
{
	phil	*one;
	int		i;
	int		j;
	int		count;
	int		die_time;
	phil	*temp;

	one = (phil *)arg;
	count = one->phil_count;
	die_time = one->die_time / 1000;
	while (1)
	{
		i = 0;
		j = 0;
		temp = one;
		while (i < count)
		{
			pthread_mutex_lock(&temp->mutex.last_meal);
			if (((get_time() - temp->last_meal) > die_time)
				&& !full_check(temp))
			{
				display_message('d', temp);
				set_dead(one);
				pthread_mutex_unlock(&temp->mutex.last_meal);
				pthread_exit(NULL);
			}
			pthread_mutex_unlock(&temp->mutex.last_meal);
			if (full_check(temp))
				j++;
			if (j == count)
				pthread_exit(NULL);
			temp = temp->next;
			i++;
			usleep(500);
		}
	}
}

void	create_threads(phil *head)
{
	phil		*temp;
	int			count;
	int			i;
	pthread_t	*tid;

	temp = head;
	count = head->phil_count;
	i = 0;
	tid = malloc((count + 1) * sizeof(pthread_t));
	while (temp && i < count)
	{
		pthread_create(&tid[i], NULL, philo_thread, temp);
		i++;
		temp = temp->next;
	}
	pthread_create(&tid[count], NULL, watch_time, head);
	i = 0;
	while (i <= count)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return ;
}

int	threads_ready(phil *head) // maybe mutex lock the ready variable
{
	phil *temp = head;
	int count = head->phil_count;
	int i = 0;
	while (temp && i < count)
	{
		if (!temp->ready)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}
