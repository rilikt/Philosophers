/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:42:23 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 15:25:13 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_dead(phil *head)
{
	int		i;
	phil	*temp;

	i = 0;
	temp = head;
	while (i < head->phil_count)
	{
		pthread_mutex_lock(&temp->mutex.dead);
		temp->dead = 1;
		pthread_mutex_unlock(&temp->mutex.dead);
		temp = temp->next;
		i++;
	}
	return ;
}

int	dead_check(phil *phil)
{
	int	re;

	re = 0;
	pthread_mutex_lock(&phil->mutex.dead);
	if (phil->dead)
		re = 1;
	pthread_mutex_unlock(&phil->mutex.dead);
	return (re);
}

int	full_check(phil *phil)
{
	int re;
	re = 0;
	if (phil->full == 0)
		return (re);
	pthread_mutex_lock(&phil->mutex.meal_count);
	if (phil->meal_count == phil->full)
		re = 1;
	pthread_mutex_unlock(&phil->mutex.meal_count);
	return (re);
}
