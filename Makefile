# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 22:32:35 by ofadhel           #+#    #+#              #
#    Updated: 2023/10/10 18:07:15 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	philo

SRC		=	main.c errors.c utils.c monitor.c

CC 		=	 gcc

FLAGS 	= 	-Wall -Wextra -Werror

OBJ 	= 	$(SRC:.c=.o)

RM 		= 	rm -rf

all		: 	$(NAME)

$(NAME)	: 	$(OBJ)
			$(CC) $(FLAGS) -o $(NAME) $(OBJ)
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
