/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:42 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 13:56:13 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_mutex
{
	pthread_mutex_t	fork;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	dead;
	pthread_mutex_t	meal_count;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	ready;

}					t_mutex;

typedef struct s_args
{
	int				ready;
	int				phil_id;
	int				phil_count;
	int				sleep_time;
	int				eat_time;
	int				die_time;
	int				last_meal;
	int				fork;
	int				dead;
	int				full;
	int				meal_count;
	t_mutex			mutex;
	struct s_args	*next;
	int				start_time;
}					phil;

void				error_msg(void);
void				free_list(phil *head);
void				create_list(phil *head);
void				print_list(phil *head);
void				die_counter(phil *phil);
void				eat(phil *phil);
int					to_micro(int milli);
void				set_forks(phil *phil);
void				grab_forks(phil *phil);
void				display_message(char c, phil *phil);
int					get_time(void);
void				go_to_bed(phil *phil);
void				set_dead(phil *head);
int					dead_check(phil *phil);
int					full_check(phil *phil);
int					threads_ready(phil *head);
void				inital_message(int count);
void				*philo_thread(void *arg);
void				*watch_time(void *arg);
void				destroy_mutex(phil *head);
void				create_mutex(phil *head);
void				create_threads(phil *head);
void				better_usleep(int time, phil *phil);
void				update_meal_count_time(phil *phil);
void				get_forks(phil *phil);
void				set_time(phil *head);
void	init_values(phil *one, int i, int value);
int check_arguments(int argc, char **argv, phil **one);
long long int	ft_atoi(const char *str);
int check_str(int argc, char **argv);


#endif