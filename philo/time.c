/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:41:25 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 15:25:05 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_time(phil *head)
{
	int		count;
	int		i;
	phil	*temp;
	int		time;

	count = head->phil_count;
	i = 0;
	temp = head;
	time = get_time();
	while (temp && i < count)
	{
		temp->start_time = time;
		temp->last_meal = time;
		temp = temp->next;
		i++;
	}
}

int	get_time(void)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
}

void	better_usleep(int time, phil *phil)
{
	int start = get_time();
	int elapsed;
	int remain;
	time /= 1000;
	while ((get_time() - start) < time)
	{
		if (dead_check(phil))
			return ;
		elapsed = get_time() - start;
		remain = time - elapsed;
		if (remain > 1)
			usleep(remain / 2);
		else
		{
			while ((get_time() - start) < time)
				;
		}
	}
}
