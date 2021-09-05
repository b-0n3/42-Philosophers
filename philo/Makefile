# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/05 18:50:44 by aait-ham          #+#    #+#              #
#    Updated: 2021/09/05 18:51:10 by aait-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
SRC= ./src/eat.c \
	 ./src/super_man.c \
	 ./src/init.c \
	 ./src/parse_args.c \
	 ./src/sleep.c \
	 ./src/think.c \
	 ./src/destructor.c \
	 main.c

INC=./headers

FLAGS= -Wall -Wextra -Werror

COMPILER=gcc $(FLAGS)


all: $(NAME)

$(NAME):
	@$(COMPILER) $(SRC) -I $(INC)  -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
