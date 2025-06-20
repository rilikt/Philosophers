/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/18 15:35:24 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_phil	*one;

	one = NULL;
	if (check_arguments(argc, argv, &one))
		return (1);
	if (create_list(one))
		return (free_list(one), 1);
	if (create_mutex(one))
		return (free_list(one), 1);
	if (create_threads(one))
		return (destroy_mutex(one, one->phil_count), free_list(one), 1);
	if (destroy_mutex(one, one->phil_count))
		return (free_list(one), 1);
	free_list(one);
	return (0);
}
