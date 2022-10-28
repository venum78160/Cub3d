NAME = gnl.a

SRCS = get_next_line_utils.c \
get_next_line.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I includes $< -o ${<:.c=.o} 

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}	

bonus: $(NAME_BONUS)


clean:
	rm -f ${OBJS} ${OBJS_bonus}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
