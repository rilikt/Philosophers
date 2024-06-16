/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:53:12 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 15:25:40 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_values(phil *new_node, phil *head)
{
	static int	id = 2;

	new_node->phil_id = id++;
	new_node->sleep_time = head->sleep_time;
	new_node->eat_time = head->eat_time;
	new_node->die_time = head->die_time;
	new_node->fork = head->fork;
	new_node->start_time = head->start_time;
	new_node->last_meal = head->last_meal;
	new_node->phil_count = head->phil_count;
	new_node->dead = head->dead;
	new_node->full = head->full;
	new_node->meal_count = head->meal_count;
	new_node->ready = head->ready;
}

phil	*find_link(phil *head)
{
	phil	*temp;

	temp = head;
	while (temp && temp->next != head)
		temp = temp->next;
	return (temp);
}

void	append_node(phil *head)
{
	phil	*new_node;
	phil	*prev;

	new_node = (phil *)malloc(sizeof(phil));
	if (!new_node)
		return (error_exit(head));
	if (!head->next)
		head->next = new_node;
	else
	{
		prev = find_link(head);
		prev->next = new_node;
	}
	new_node->next = head;
	set_values(new_node, head);
}

void	create_list(phil *head)
{
	int count = head->phil_count;
	while (count > 1)
	{
		append_node(head);
		count--;
	}
}
