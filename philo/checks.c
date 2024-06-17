/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:42:23 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 16:35:29 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_dead(t_phil *head)
{
	int		i;
	t_phil	*temp;

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

int	dead_check(t_phil *phil)
{
	int	re;

	re = 0;
	pthread_mutex_lock(&phil->mutex.dead);
	if (phil->dead)
		re = 1;
	pthread_mutex_unlock(&phil->mutex.dead);
	return (re);
}

int	full_check(t_phil *phil)
{
	int	re;

	re = 0;
	if (phil->full == 0)
		return (re);
	pthread_mutex_lock(&phil->mutex.meal_count);
	if (phil->meal_count == phil->full)
		re = 1;
	pthread_mutex_unlock(&phil->mutex.meal_count);
	return (re);
}

int	all_full(t_phil *head)
{
	int		i;
	int		j;
	int		count;
	t_phil	*temp;

	i = 0;
	j = 0;
	count = head->phil_count;
	temp = head;
	while (temp && i < count)
	{
		if (full_check(temp))
			j++;
		if (j == count)
			return (1);
		i++;
	}
	return (0);
}

int	check_death_time(t_phil *head, int die_time, int count)
{
	t_phil	*temp;
	int		i;

	temp = head;
	i = 0;
	while (temp && i < count)
	{
		pthread_mutex_lock(&temp->mutex.last_meal);
		if (((get_time() - temp->last_meal) > die_time) && !full_check(temp))
		{
			display_message('d', temp);
			set_dead(temp);
			pthread_mutex_unlock(&temp->mutex.last_meal);
			return (1);
		}
		pthread_mutex_unlock(&temp->mutex.last_meal);
		temp = temp->next;
		i++;
	}
	return (0);
}
