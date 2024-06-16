/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:05:13 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/16 13:43:31 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void error_exit(phil *head)
{
	write(2, "Error\n", 6);
	free_list(head);
	exit(2); // exit function not allowed
}