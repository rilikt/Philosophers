/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 16:34:19 by timschmi         ###   ########.fr       */
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
	inital_message(one->phil_count);
	if (create_threads(one))
		return (destroy_mutex(one, one->phil_count), free_list(one), 1);
	destroy_mutex(one, one->phil_count);
	free_list(one);
	return (0);
}
