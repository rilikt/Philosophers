/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:26:31 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/14 13:33:23 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int threads_ready(phil *head) // maybe mutex lock the ready variable
{
	phil *temp = head;
	int count = head->phil_count;
	int i = 0;
	while (temp && i < count)
	{
		if (!temp->ready)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

void inital_message(phil *phil)
{
	static int i = 1;
	while(1)
	{
		if (i == phil->phil_id && i <= phil->phil_count)
		{
			display_message('t', phil);
			i++;
			return;
		}
		usleep(50);
	}
}
