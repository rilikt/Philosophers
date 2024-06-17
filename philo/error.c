/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:05:13 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 13:01:55 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void error_msg(void)
{
	printf("Error.\n");
	printf("============================================================\n");
	printf("Please input:\n");
	printf("number_of_philosophers starting form at least 1\n");
	printf("time_to_die in ms\n");
	printf("time_to_eat in ms\n");
	printf("time_to_sleep\n");
	printf("and optional number_of_times_each_philosopher_must_eat\n");
	printf("all values should be positive and within the range of INT\n");
	printf("============================================================\n");



	

	// free_list(head);
}
