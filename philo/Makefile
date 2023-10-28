# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 22:32:35 by ofadhel           #+#    #+#              #
#    Updated: 2023/10/28 20:51:02 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	philo

SRC		=	main.c errors.c utils1.c routine.c thread.c monitor.c

CC 		=	 gcc

FLAGS 	= 	-Wall -Wextra -Werror -pthread

OBJ 	= 	$(SRC:.c=.o)

%.o: %.c
			$(CC) -c $< -o $@


RM 		= 	rm -rf

all		: 	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(OBJ) $(FLAGS) -o $(NAME)
			@echo ""
			@echo "\033[0;36m  PHILOSOPHERS\033[0m"
			@echo ""

clean	:
			$(RM) $(OBJ)

fclean	: 	clean
			$(RM) $(NAME) $(OBJ)
			@echo "\033[0;32mFiles Removed!\033[0m"

re		:	fclean all

.PHONY	: 	all clean fclean re
