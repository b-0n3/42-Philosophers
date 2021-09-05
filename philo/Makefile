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