/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:06:54 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/14 15:48:23 by timschmi         ###   ########.fr       */
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
		usleep(phil->eat_time); // program needs to exit while someone is eating aswell

		set_forks(phil);
		go_to_bed(phil);
	}
	else
		return;
}

int get_time(void)
{	
	struct timeval curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
}

void set_dead(phil *head)
{
	int i = 0;
	phil *temp;
	temp = head;
	while(i < head->phil_count)
	{
		pthread_mutex_lock(&temp->mutex.dead);
		temp->dead = 1;
		pthread_mutex_unlock(&temp->mutex.dead);
		temp = temp->next;
		i++;
	}
	return ;
}

int dead_check(phil *phil)
{
	int re;
	re = 0;
	pthread_mutex_lock(&phil->mutex.dead);
	if (phil->dead)
		re = 1;
	pthread_mutex_unlock(&phil->mutex.dead);
	return (re);
}

int full_check(phil *phil)
{
	int re;
	re = 0;
	pthread_mutex_lock(&phil->mutex.meal_count);
	if (phil->meal_count == phil->full)
		re = 1;
	pthread_mutex_unlock(&phil->mutex.meal_count);
	return (re);
}
