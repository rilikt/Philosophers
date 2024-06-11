/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:06:54 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/11 18:56:36 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_list(phil *head)
{
	phil *temp = head;

	while (temp)
	{
		printf("id: %d, s_time: %d, e_time: %d, d_time: %d, fork: %d tv_start: %d last meal:%d\n", temp->phil_id, temp->sleep_time, temp->eat_time, temp->die_time, temp->fork, temp->start_time, temp->last_meal);
		if (temp->next == head)
			return;
		temp = temp->next;
	}
}

void free_list(phil *head)
{
	phil *temp = head;
	phil *nxt;

	while(temp)
	{
		nxt = temp->next;
		free(temp);
		temp = nxt;
	}
	if (head)
		free (head);	
}

int to_micro(int milli) // maybe choose a larger data type
{
	return (milli * 1000);
}

void set_forks(phil *phil)
{
	pthread_mutex_lock(&phil->mutex.fork);
	pthread_mutex_lock(&phil->next->mutex.fork);


	if (!phil->fork && !phil->next->fork)
	{
		phil->fork = 1;
		phil->next->fork = 1;
	}

	pthread_mutex_unlock(&phil->mutex.fork);
	pthread_mutex_unlock(&phil->next->mutex.fork);


}

void grab_forks(phil *phil)
{
	pthread_mutex_lock(&phil->mutex.fork);
	pthread_mutex_lock(&phil->next->mutex.fork);

	if (phil->fork && phil->next->fork)
	{
		display_message('f', phil);
		display_message('f', phil);
		phil->fork = 0;
		phil->next->fork = 0;
		pthread_mutex_unlock(&phil->mutex.fork);
		pthread_mutex_unlock(&phil->next->mutex.fork);
		phil->last_meal = get_time();

		display_message('e', phil);
		usleep(phil->eat_time);

		set_forks(phil);
		go_to_bed(phil);
	}
	pthread_mutex_unlock(&phil->mutex.fork);
	pthread_mutex_unlock(&phil->next->mutex.fork);

}

int get_time(void)
{	
	struct timeval curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
}