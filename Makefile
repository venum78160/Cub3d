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

MLX	=	-lft -lmlx -framework OpenGL -framework AppKit

SRCS = srcs/main.c \
		$(addprefix srcs/helpful/, helpful.c raycasting_help.c) \
		parsing/parsing.c \
		parsing/open_doc.c \
		parsing/utils/errors.c \
		parsing/utils/ft_gnljoin.c \
		parsing/utils/get_extension.c \
		parsing/utils/gnl.c \
		parsing/lib/ft_strcmp.c \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: ${NAME}

.c.o: $(SRCS)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)
	
${NAME}: ${OBJS}
		@make -C Libft
		@make bonus -C Libft
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(LIB)$(GREEN)" has been created\n"$(RESET)
		@make -C ./minilibx 2>/dev/null
		@$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) -lm -L ./libft -lft -lmlx -framework OpenGL -framework AppKit -L ./minilibx
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(FRONTNAME)$(GREEN)" has been created\n"$(RESET)

clean :
		@${RM} ${OBJS} $(LIB)
		@make clean -C Libft
		@printf $(RED)"\r\033[K➜ ["$(FRONTNAME)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
		@printf $(RED)"\r\033[K➜ [LIB] library folder has been "$(WHITE)"removed"$(RED)"\n"$(RESET)

fclean: clean
		@printf $(GREEN)"\r\033[K🗑️  Deleted: "$(WHITE)$(FRONTNAME)$(RED)" has been deleted\n"$(RESET)
		@${RM} ${NAME}
		
re: fclean all

.PHONY: all clean fclean re 