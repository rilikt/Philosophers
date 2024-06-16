/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:06:54 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 14:28:06 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void increment_meal_count(phil *phil)
{
	pthread_mutex_lock(&phil->mutex.meal_count);
	if (phil->meal_count < phil->full)
		phil->meal_count += 1;
	pthread_mutex_unlock(&phil->mutex.meal_count);
}

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
	phil *next;
	int i = 0;
	int count = head->phil_count;

	if (head == NULL)
		return;
	while(temp && i < count)
	{
		next = temp->next;
		free(temp);
		temp = next;
		i++;
	}
}

int to_micro(int milli) // maybe choose a larger data type
{
	return (milli * 1000);
}

void get_forks(phil *phil)
{
	if (dead_check(phil)) // this can be removed maybe
		return;
	pthread_mutex_lock(&phil->mutex.fork);
	pthread_mutex_lock(&phil->next->mutex.fork);
	if (phil->fork && phil->next->fork)
	{
		phil->fork = 0;
		phil->next->fork = 0;
	}
	else
	{
		pthread_mutex_unlock(&phil->mutex.fork);
		pthread_mutex_unlock(&phil->next->mutex.fork);
		eat(phil);
	}
}

void set_forks(phil *phil)
{
	if (dead_check(phil)) // this can be removed maybe
		return;

	if (!phil->fork && !phil->next->fork)
	{
		phil->fork = 1;
		phil->next->fork = 1;
	}
}

void grab_forks(phil *phil)
{
	if (phil->fork && phil->next->fork)
	{
		get_forks(phil);
		display_message('f', phil);
		display_message('f', phil);

		phil->last_meal = get_time();
		increment_meal_count(phil);
		
		display_message('e', phil);
		better_usleep(phil->eat_time, phil); // program needs to exit while someone is eating aswell

		set_forks(phil);
		go_to_bed(phil);
	}
	else
		return;
}




