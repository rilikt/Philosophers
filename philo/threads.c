/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:57:37 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/18 16:44:36 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *arg)
{
	t_phil	*one;

	one = (t_phil *)arg;
	pthread_mutex_lock(&one->mutex.ready);
	one->ready = 1;
	pthread_mutex_unlock(&one->mutex.ready);
	if ((one->phil_id % 2) != 0 && one->next)
		better_usleep((one->eat_time / 2), one);
	eat(one);
	pthread_exit(NULL);
}

void	*watch_time(void *arg)
{
	t_phil	*one;
	int		count;
	int		die_time;

	one = (t_phil *)arg;
	count = one->phil_count;
	die_time = one->die_time;
	while (1)
	{
		if (check_death_time(one, die_time, count))
			pthread_exit(NULL);
		else if (all_full(one))
			pthread_exit(NULL);
		usleep(500);
	}
}

int	create_threads(t_phil *head)
{
	t_phil		*temp;
	int			count;
	int			i;
	pthread_t	*tid;

	temp = head;
	count = head->phil_count;
	i = 0;
	tid = malloc((count + 1) * sizeof(pthread_t));
	if (!tid)
		return (printf("malloc error.\n"), 1);
	while (temp && i < count)
	{
		if (pthread_create(&tid[i], NULL, philo_thread, temp) != 0)
			return (printf("thread creation failed\n"), join_threads(tid, i),
				1);
		display_message('t', temp);
		i++;
		temp = temp->next;
	}
	if (pthread_create(&tid[count], NULL, watch_time, head) != 0)
		return (printf("thread creation failed\n"), join_threads(tid, i), 1);
	return (join_threads(tid, count + 1));
}

int	join_threads(pthread_t *tid, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_join(tid[i], NULL) != 0)
		{
			printf("failed to join thread\n");
			free(tid);
			return (1);
		}
		i++;
	}
	free(tid);
	return (0);
}
