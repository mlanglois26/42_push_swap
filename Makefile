# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 15:00:02 by malanglo          #+#    #+#              #
#    Updated: 2024/01/12 19:12:02 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRCS = 			srcs/split.c\
				srcs/utils.c\
				set/init.c\
				set/indexation.c\
				parsing/check_char.c\
				parsing/check_int.c\
				parsing/errors.c\
				parsing/parse.c\
				moves/push.c\
				moves/reverse_rotate.c\
				moves/rotate.c\
				moves/swap.c\
				sorting/sort.c\
				sorting/simple_sort_1.c\
				sorting/simple_sort_2.c\
				sorting/simple_sort_3.c\
				sorting/sort_utils.c\
				sorting/main.c\
				
OBJS =		$(SRCS:.c=.o)

all: $(NAME)

$(NAME):		${OBJS}
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re