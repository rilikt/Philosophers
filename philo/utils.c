/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:06:54 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/10 13:05:51 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_list(phil *head)
{
	phil *temp = head;

	while (temp)
	{
		printf("id: %d, s_time: %d, e_time: %d, d_time: %d, fork: %d tv_start: %d last meal:%d\n", temp->phil_id, temp->sleep_time, temp->eat_time, temp->die_time, temp->fork, temp->tv_start->tv_usec, temp->last_meal);
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
	if (phil->fork && phil->next->fork)
	{
		phil->fork = 0;
		phil->next->fork = 0;
	}
	else if (!phil->fork && !phil->next->fork)
	{
		phil->fork = 1;
		phil->next->fork = 1;
	}
}

int get_time(phil *phil)
{	
	struct timeval curr;

	if (gettimeofday(&curr, NULL) == -1)
		error_exit(phil);
	return ((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
}