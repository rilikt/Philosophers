/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:42 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/07 16:43:14 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_args
{
	int phil_id;
	int phil_count;
	int sleep_time;
	int eat_time;
	int die_time;
	int fork;
	struct s_args *next;
}	phil;

void error_exit(phil *head);
void free_list(phil *head);
void create_list(phil *head);
void print_list(phil *head);
void die_counter(phil *phil);
void eat(phil *phil);

#endif