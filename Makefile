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
		utils.c\

FILES_BONUS =	main_bonus.c\
				move_bonus.c\
				hooks_bonus.c\
				paint_bonus.c\
				load_bonus.c\
				map_bonus.c\
				split_bonus.c\
				strlen_bonus.c\
				strjoin_bonus.c\
				calloc_bonus.c\
				utils_bonus.c\

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(FILES_BONUS:.c=.o)

ifdef BONUS
RELEVANT_OBJS = $(OBJS_BONUS)
else
RELEVANT_OBJS = $(OBJS)
endif

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	@$(CC) $(FLAGS) -I./bonus -c $<
	@echo "Compiling $<"

$(NAME): $(RELEVANT_OBJS)
	@$(CC) $(MLX_FLAGS) $(RELEVANT_OBJS) -o $(NAME)
	@echo "Compiling so_long"

bonus: 
	@$(MAKE) BONUS=1

all: $(NAME)

clean:
	@rm -rf ${OBJS} ${OBJS_BONUS}
	@echo "Removing executable"

fclean: clean
	@rm -f $(NAME)

re: fclean | all

.PHONY: all clean fclean re bonus