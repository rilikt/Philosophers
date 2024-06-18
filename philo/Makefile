# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 14:53:53 by timschmi          #+#    #+#              #
#    Updated: 2024/06/18 16:03:55 by timschmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = init_list.c main.c error.c utils.c sleep.c message.c mutex.c threads.c time.c checks.c eat.c arguments.c

OFILES = $(SRCS:.c=.o)

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re