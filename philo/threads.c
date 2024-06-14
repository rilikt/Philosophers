/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:57:37 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/14 16:02:27 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(phil *head)
{
	phil *temp = head;
	int count = head->phil_count;
	int i = 0;
	pthread_t *tid = malloc((count + 1) * sizeof(pthread_t));
	while (temp && i < count)
	{
		pthread_create(&tid[i], NULL, philo_thread, temp);
		i++;
		temp = temp->next;
	}
	pthread_create(&tid[count], NULL, watch_time, head);
	i = 0;
	while (i <= count)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return;
}

