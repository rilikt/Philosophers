/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:39:27 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 16:33:08 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_message(char c, t_phil *phil)
{
	int	t_stamp;

	if (dead_check(phil) || all_full(phil))
		return ;
	t_stamp = get_time() - phil->start_time;
	pthread_mutex_lock(&phil->mutex.print_mutex);
	if (c == 'e')
		printf("%d %d is eating\n", t_stamp, phil->phil_id);
	else if (c == 'f')
		printf("%d %d has taken a fork\n", t_stamp, phil->phil_id);
	else if (c == 's')
		printf("%d %d is sleeping\n", t_stamp, phil->phil_id);
	else if (c == 't')
		printf("%d %d is thinking\n", t_stamp, phil->phil_id);
	else if (c == 'd')
		printf("%d %d died\n", t_stamp, phil->phil_id);
	pthread_mutex_unlock(&phil->mutex.print_mutex);
}

void	inital_message(int count)
{
	int	i;

	i = 1;
	while (i <= count)
	{
		printf("0 %d is thinking\n", i);
		i++;
	}
}
