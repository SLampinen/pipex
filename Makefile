# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slampine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 10:08:47 by slampine          #+#    #+#              #
#    Updated: 2023/04/26 10:08:48 by slampine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SOURCES = pipex.c utils.c
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJECTS) pipex.h
	$(MAKE) -C libft
	cp libft/libft.a libft.a
	cc $(CFLAGS) $(OBJECTS) -o $(NAME) libft.a 
clean:
	rm -f $(OBJECTS)
	$(MAKE) clean -C./libft
fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re