GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = Cub3d

FRONTNAME = CUB3d

CC = gcc
 
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

HEADER = -I./includes -I./libft -I./minilibx

LIB		=	libft.a

MINILBX		=	minilibx

MLX	=	-lft -lmlx -framework OpenGL -framework AppKit

SRCS = srcs/main.c \
		$(addprefix srcs/helpful/, helpful.c raycasting_help.c) \
		$(addprefix srcs/minimap/, minimap.c) \
		$(addprefix srcs/raycasting/, calcul.c key_event.c texture.c) \
		parsing/parsing.c \
		parsing/open_doc.c \
		parsing/utils/errors.c \
		parsing/utils/ft_gnljoin.c \
		parsing/utils/get_extension.c \
		parsing/utils/gnl.c \
		parsing/utils/bonus.c \
		parsing/utils/check_extension.c \
		parsing/utils/free_parsing.c \
		parsing/utils/id.c \
		parsing/utils/line_check.c \
		parsing/utils/path.c \
		parsing/utils/remove_newline.c \
		parsing/utils/rgb.c \
		parsing/utils/spawn.c \
		parsing/utils/valid.c \
		parsing/utils/wall_check.c \
		parsing/lib/ft_strcmp.c \
		parsing/lib/clear_lst.c \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: ${NAME}

.c.o: $(SRCS)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)
	
${NAME}: ${OBJS}
		@make bonus -C Libft
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(LIB)$(GREEN)" has been created\n"$(RESET)
		@make -C ./minilibx 2>/dev/null
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(MINILBX)$(GREEN)" has been created\n"$(RESET)
		@$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) -lm -L ./libft -lft -lmlx -framework OpenGL -framework AppKit -L ./minilibx
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(FRONTNAME)$(GREEN)" has been created\n"$(RESET)

clean :
		@${RM} ${OBJS} $(LIB)
		@make clean -C Libft
		@printf $(RED)"\r\033[K➜ [LIB] library folder has been "$(WHITE)"removed"$(RED)"\n"$(RESET)
		@make clean -C ./minilibx
		@printf $(RED)"\r\033[K➜ [MINILIBX] library folder has been "$(WHITE)"removed"$(RED)"\n"$(RESET)
		@printf $(RED)"\r\033[K➜ ["$(FRONTNAME)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)

fclean: clean
		@printf $(GREEN)"\r\033[K🗑️  Deleted: "$(WHITE)$(FRONTNAME)$(RED)" has been deleted\n"$(RESET)
		@${RM} ${NAME}
		
re: fclean all

.PHONY: all clean fclean re 