NAME = so_long

CC = gcc

FLAGS = -Wall -Werror -Wextra

FILES =	main.c\
		move.c\
		hooks.c\
		paint.c\
		load.c\
		map.c\
		split.c\
		strlen.c\
		strjoin.c\
		calloc.c\

$(NAME): 
	@$(CC) -Imlx $(FLAGS) $(FILES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Compiling so_long"

all: $(NAME)

clean:
	@rm -f $(NAME)
	@echo "Removing executable"

fclean: clean

re: fclean | all

.PHONY: all clean fclean re