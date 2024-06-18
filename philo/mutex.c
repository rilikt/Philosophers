/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:54:58 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/18 16:50:42 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mutex(t_phil *head)
{
	t_phil			*temp;
	pthread_mutex_t	print;
	int				count;
	int				i;

	temp = head;
	count = head->phil_count;
	i = 0;
	if (pthread_mutex_init(&print, NULL) != 0)
		return (printf("mutex init failed.\n"), 1);
	while (temp && i < count)
	{
		if (pthread_mutex_init(&temp->mutex.fork, NULL) != 0
			|| pthread_mutex_init(&temp->mutex.last_meal, NULL) != 0
			|| pthread_mutex_init(&temp->mutex.dead, NULL) != 0
			|| pthread_mutex_init(&temp->mutex.meal_count, NULL) != 0)
			return (printf("mutex init failed.\n"), destroy_mutex(head, i), 1);
		temp->mutex.print_mutex = print;
		i++;
		temp = temp->next;
	}
	return (0);
}

int	destroy_mutex(t_phil *head, int count)
{
	t_phil	*temp;
	int		i;

	temp = head;
	i = 0;
	pthread_mutex_destroy(&temp->mutex.print_mutex);
	while (i < count)
	{
		if (pthread_mutex_destroy(&temp->mutex.fork) != 0
			|| pthread_mutex_destroy(&temp->mutex.last_meal) != 0
			|| pthread_mutex_destroy(&temp->mutex.dead) != 0
			|| pthread_mutex_destroy(&temp->mutex.meal_count) != 0)
		{
			printf("mutex destroy failed.\n");
			return (1);
		}
		i++;
		temp = temp->next;
	}
	return (0);
}
