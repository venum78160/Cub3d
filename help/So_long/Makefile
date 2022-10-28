
GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = so_long

PROJECT = so_long

SRCS = main.c \
	affichage.c \
	deplacement.c \
	fonction_aff.c \
	fonction_utile.c \
	test_maps.c \
	map.c \
	affichage2.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = -I./includes -I./Libft -I./gnl -I./minilibx

all: $(NAME)

.c.o: $(SRCS)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@make -C ./minilibx 2>/dev/null
	@make -C ./gnl
	@make bonus -C ./Libft
	@gcc $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) -lm -L ./Libft -lft -lmlx -framework OpenGL -framework AppKit gnl/gnl.a -L ./minilibx
	@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(NAME)$(GREEN)" has been created\n"$(RESET)

clean:
	@rm -rf $(OBJS)
	@make clean -C ./Libft
	@make clean -C ./gnl
	@make clean -C ./minilibx
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)

fclean:
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@rm -rf ./Libft/libft.a
	@make fclean -C ./Libft
	@make fclean -C ./gnl
	@make clean -C ./minilibx
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"fclean"$(RED)" has been done\n"$(RESET)


re: fclean all

.PHONY: all clean fclean re

