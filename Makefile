#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 16:01:22 by ayavorsk          #+#    #+#              #
#    Updated: 2017/10/24 16:01:22 by ayavorsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

HEAD = lem_in.h

SRC = main.c\
		print_move_ants.c\
		start_search_short_path.c\
		ft_helpfunctions.c\
		parse_lem_data.c\
		search_short_path.c\
		parse_functions.c\
		list_functions.c\
		get_next_line.c\
		search_length.c\
		move_ants.c\
		parse_ants.c\
		parse_room.c\
		parse_link.c\
		move_ants_2.c\
		free_all_unusing.c\
		debug_mod_activated.c\
		one_path.c\
	
		
LIBFT = libft_42/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) -g $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -lft

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: re all clean fclean