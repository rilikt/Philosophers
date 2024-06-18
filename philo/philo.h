/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:37:42 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/18 16:45:09 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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
}					t_phil;

void				error_msg(void);
void				free_list(t_phil *head);
int					create_list(t_phil *head);
void				eat(t_phil *phil);
void				set_forks(t_phil *phil);
void				grab_forks(t_phil *phil);
void				display_message(char c, t_phil *phil);
int					get_time(void);
void				go_to_bed(t_phil *phil);
void				set_dead(t_phil *head);
int					dead_check(t_phil *phil);
int					full_check(t_phil *phil);
void				inital_message(int count);
void				*philo_thread(void *arg);
void				*watch_time(void *arg);
int					destroy_mutex(t_phil *head, int count);
int					create_mutex(t_phil *head);
int					create_threads(t_phil *head);
void				better_usleep(int time, t_phil *phil);
void				update_meal_time(t_phil *phil);
void				get_forks(t_phil *phil);
void				init_values(t_phil *one, int i, int value);
int					check_arguments(int argc, char **argv, t_phil **one);
long long int		ft_atoi(const char *str);
int					check_str(int argc, char **argv);
int					check_death_time(t_phil *temp, int die_time, int count);
int					all_full(t_phil *head);
void				update_meal_count(t_phil *phil);
int					join_threads(pthread_t *tid, int count);
void				think_offset(t_phil *phil);
void				set_time(t_phil *head);

#endif