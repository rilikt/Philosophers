/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:54:58 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 13:57:35 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mutex(phil *head)
{
	phil	*temp;
	pthread_mutex_t print;

	int		count;
	int		i;

	temp = head;
	count = head->phil_count;
	i = 0;
	pthread_mutex_init(&print, NULL);
	while (temp && i < count)
	{
		pthread_mutex_init(&temp->mutex.fork, NULL);
		pthread_mutex_init(&temp->mutex.last_meal, NULL);
		pthread_mutex_init(&temp->mutex.dead, NULL);
		pthread_mutex_init(&temp->mutex.meal_count, NULL);
		temp->mutex.print_mutex = print;
		i++;
		temp = temp->next;
	}
	return ;
}

void	destroy_mutex(phil *head)
{
	phil	*temp;
	int		count;
	int		i;

	temp = head;
	count = head->phil_count;
	i = 0;
	pthread_mutex_destroy(&temp->mutex.print_mutex);
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
