/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:41:25 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/18 15:47:15 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
}

void	better_usleep(int time, t_phil *phil)
{
	int	start;
	int	elapsed;
	int	remain;

	start = get_time();
	while ((get_time() - start) < time)
	{
		if (dead_check(phil) || all_full(phil))
			return ;
		elapsed = get_time() - start;
		remain = time - elapsed;
		if (remain > 1)
			usleep((remain / 2) * 1000);
		else
		{
			while ((get_time() - start) < time)
				;
		}
	}
}

void	think_offset(t_phil *phil)
{
	int	wait;

	wait = (phil->eat_time * 2) - phil->sleep_time;
	if (wait > 0)
		better_usleep((wait / 2), phil);
}
