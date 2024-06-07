/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:06:54 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/07 15:41:31 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_list(phil *head)
{
	phil *temp = head;

	while (temp)
	{
		printf("id: %d, s_time: %d, e_time: %d, d_time: %d, fork: %d\n", temp->phil_id, temp->sleep_time, temp->eat_time, temp->die_time, temp->fork);
		if (temp->next == head)
			return;
		temp = temp->next;
	}
}

void free_list(phil *head)
{
	phil *temp = head;
	phil *nxt;

	while(temp)
	{
		nxt = temp->next;
		free(temp);
		temp = nxt;
	}
	if (head)
		free (head);
	
}