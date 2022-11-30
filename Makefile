GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = cub3D

FRONTNAME = CUB3d

CC = gcc
 
CFLAGS = -Wall -Wextra -Werror

HEADER = -I./includes -I./libft -I./minilibx

LIB		=	libft.a

MINILBX		=	minilibx

MLX	=	-lft -lmlx -framework OpenGL -framework AppKit

SRCS = srcs/main.c \
		$(addprefix srcs/helpful/, helpful.c raycasting_help.c mouse.c) \
		$(addprefix srcs/minimap/, minimap.c) \
		$(addprefix srcs/raycasting/, calcul.c key_event.c texture.c door.c fonct_mv.c) \
		srcs/parsing/parsing.c \
		srcs/parsing/open_doc.c \
		srcs/parsing/utils/errors.c \
		srcs/parsing/utils/ft_gnljoin.c \
		srcs/parsing/utils/get_extension.c \
		srcs/parsing/utils/gnl.c \
		srcs/parsing/utils/check_extension.c \
		srcs/parsing/utils/free_parsing.c \
		srcs/parsing/utils/id.c \
		srcs/parsing/utils/line_check.c \
		srcs/parsing/utils/path.c \
		srcs/parsing/utils/remove_newline.c \
		srcs/parsing/utils/rgb.c \
		srcs/parsing/utils/spawn.c \
		srcs/parsing/utils/valid.c \
		srcs/parsing/utils/wall_check.c \
		srcs/parsing/lib/ft_strcmp.c \
		srcs/parsing/lib/clear_lst.c \

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