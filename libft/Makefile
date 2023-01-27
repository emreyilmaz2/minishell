# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:50:31 by acomak            #+#    #+#              #
#    Updated: 2023/01/27 19:01:15 by emyilmaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = $(wildcard ./source/ft_*.c)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

re : fclean all

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

.PHONY : all bonus clean fclean re
