/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:11 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 13:54:14 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	phil	*one;
	one = NULL;
	
	if (check_arguments(argc, argv, &one))
		return(1);

	create_list(one);
	create_mutex(one);
	// set_time(one);
	inital_message(one->phil_count);
	create_threads(one);
	destroy_mutex(one);
	free_list(one);
	return (0);
}
