/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:51:24 by timschmi          #+#    #+#             */
/*   Updated: 2024/06/17 20:40:12 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arguments(int argc, char **argv, t_phil **one)
{
	int			i;
	long int	n;

	i = 1;
	if ((argc != 5 && argc != 6) || check_str(argc, argv))
		return (error_msg(), 1);
	*one = (t_phil *)malloc(sizeof(t_phil));
	if (*one == NULL)
		return (printf("malloc error.\n"), 1);
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n < 0 || n > INT_MAX || (i == 1 && n == 0))
			return (free(*one), error_msg(), 1);
		else
			init_values(*one, i, n);
		i++;
	}
	if (argc == 4)
		init_values(*one, 6, 0);
	init_values(*one, 0, 0);
	return (0);
}

long long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	num;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

void	init_values(t_phil *one, int i, int value)
{
	if (i == 1)
		one->phil_count = value;
	else if (i == 2)
		one->die_time = value;
	else if (i == 3)
		one->eat_time = value;
	else if (i == 4)
		one->sleep_time = value;
	else if (i == 5)
		one->full = value;
	else if (i == 6)
		one->full = value;
	else
	{
		one->phil_id = 1;
		one->dead = 0;
		one->meal_count = 0;
		one->fork = 1;
		one->next = NULL;
		one->start_time = get_time();
		one->last_meal = one->start_time;
		one->ready = 0;
		one->t_sync = 0;
	}
}

int	check_str(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (i > 9 || !((argv[j][i] >= '0' && argv[j][i] <= '9')
					|| argv[j][i] == '+'))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
