/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:53:12 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/18 16:50:01 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_values(t_phil *new_node, t_phil *head)
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
	new_node->dead = 0;
	new_node->full = head->full;
	new_node->meal_count = 0;
}

t_phil	*find_link(t_phil *head)
{
	t_phil	*temp;

	temp = head;
	while (temp && temp->next != head)
		temp = temp->next;
	return (temp);
}

int	append_node(t_phil *head)
{
	t_phil	*new_node;
	t_phil	*prev;

	new_node = (t_phil *)malloc(sizeof(t_phil));
	if (!new_node)
		return (printf("malloc error.\n"), 1);
	if (!head->next)
		head->next = new_node;
	else
	{
		prev = find_link(head);
		prev->next = new_node;
	}
	new_node->next = head;
	set_values(new_node, head);
	return (0);
}

int	create_list(t_phil *head)
{
	int	count;

	count = head->phil_count;
	while (count > 1)
	{
		if (append_node(head))
			return (1);
		count--;
	}
	return (0);
}
