/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:42 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/11 18:01:07 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct s_mutex
{
	pthread_mutex_t fork;

}	t_mutex;

typedef struct s_args
{
	int phil_id;
	int phil_count;
	int sleep_time;
	int eat_time;
	int die_time;
	int last_meal;
	int fork;
	t_mutex mutex;
	struct s_args *next;
	int start_time;
}	phil;


void error_exit(phil *head);
void free_list(phil *head);
void create_list(phil *head);
void print_list(phil *head);
void die_counter(phil *phil);
void eat(phil *phil);
int to_micro(int milli);
void set_forks(phil *phil);
void grab_forks(phil *phil);
void display_message(char c, phil *phil);
int get_time(void);
void go_to_bed(phil *phil);

#endif