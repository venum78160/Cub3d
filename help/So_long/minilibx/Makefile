#
#
GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS=-O2 -DSTRINGPUTX11


all: $(NOM)

.m.o: $(OBJ)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $(<:.m=.o)

.c.o: $(SRCS)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
