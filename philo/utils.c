/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:06:54 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 16:49:59 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_meal_count_time(phil *phil)
{
	pthread_mutex_lock(&phil->mutex.last_meal);
	phil->last_meal = get_time();
	pthread_mutex_unlock(&phil->mutex.last_meal);
	pthread_mutex_lock(&phil->mutex.meal_count);
	if (phil->meal_count < phil->full)
		phil->meal_count += 1;
	pthread_mutex_unlock(&phil->mutex.meal_count);
}

// void	print_list(phil *head)
// {
// 	phil	*temp;

// 	temp = head;
// 	while (temp)
// 	{
// 		printf("id: %d, s_time: %d, e_time: %d, d_time: %d, fork: %d tv_start:
// 			%d last meal:%d\n", temp->phil_id, temp->sleep_time, temp->eat_time,
// 			temp->die_time, temp->fork, temp->start_time, temp->last_meal);
// 		if (temp->next == head)
// 			return ;
// 		temp = temp->next;
// 	}
// }

void	free_list(phil *head)
{
	phil	*temp;
	phil	*next;
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

int	to_micro(int milli) // maybe choose a larger data type
{
	return (milli * 1000);
}


