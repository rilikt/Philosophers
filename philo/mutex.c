/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:54:58 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/14 16:03:36 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_mutex(phil *head)
{
	phil *temp = head;
	int count = head->phil_count;
	int i = 0;
	while (temp && i < count)
	{
		pthread_mutex_init(&temp->mutex.fork, NULL);
		pthread_mutex_init(&temp->mutex.last_meal, NULL);
		pthread_mutex_init(&temp->mutex.dead, NULL);
		pthread_mutex_init(&temp->mutex.meal_count, NULL);
		i++;
		temp = temp->next;
	}
	return;
}

void destroy_mutex(phil *head)
{
	phil *temp = head;
	int count = head->phil_count;
	int i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&temp->mutex.fork);
		pthread_mutex_destroy(&temp->mutex.last_meal);
		pthread_mutex_destroy(&temp->mutex.dead);
		pthread_mutex_destroy(&temp->mutex.meal_count);
		i++;
		temp = temp->next;
	}
}
