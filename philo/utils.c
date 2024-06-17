/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:06:54 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 16:43:05 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_meal_time(t_phil *phil)
{
	pthread_mutex_lock(&phil->mutex.last_meal);
	phil->last_meal = get_time();
	pthread_mutex_unlock(&phil->mutex.last_meal);
}

void	update_meal_count(t_phil *phil)
{
	pthread_mutex_lock(&phil->mutex.meal_count);
	if (phil->meal_count < phil->full)
		phil->meal_count += 1;
	pthread_mutex_unlock(&phil->mutex.meal_count);
}

void	free_list(t_phil *head)
{
	t_phil	*temp;
	t_phil	*next;
	int		i;
	int		count;

	temp = head;
	i = 0;
	count = head->phil_count;
	if (head == NULL)
		return ;
	while (temp && i < count)
	{
		next = temp->next;
		free(temp);
		temp = next;
		i++;
	}
}
