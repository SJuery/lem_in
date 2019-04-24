# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 11:28:46 by sjuery            #+#    #+#              #
#    Updated: 2018/02/06 07:18:58 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

SRC		= 	srcs/lemin.c \
			srcs/create_envi.c \
			srcs/algorithm.c \

OBJ 	= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror -g
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	printf '\033[31m[...] %s\n\033[0m' "Creating Lem-in Program"
	make -C srcs/libft/
	gcc $(CFLAG) srcs/libft/libft.a $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created Lem-in Program"

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning Lem-in Program"
	make fclean -C srcs/libft/
	/bin/rm -f srcs/*.o
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaned Lem-in Program"

fclean: clean
	make fclean -C srcs/libft/
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
