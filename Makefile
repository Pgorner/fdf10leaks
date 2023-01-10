
#	███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗
#	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝
#	██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗
#	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝
#	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗
#	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝

NAME = fdf

CC		 = cc
CFLAGS   = -Wall -Werror -Wextra
MLXFLAGS = -lglfw -L "$(HOME)/homebrew/Cellar/glfw/3.3.8/lib/"
AR		 = ar rcs
RM		 = rm -rf
FSANITIZE = -fsanitize=address -g

.SILENT:
			libft
			printf
			clean
			all
			$(NAME)

SRC =		fdf.c						\
			get_input.c					\
			start_mlx.c					\

OBJS =		$(SRC:.c=.o)

LIBFT =	./42-libft/libft.a
MLX42 =	./MLX42/libmlx42.a

$(NAME):	$(MLX42) $(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(MLX42) $(LIBFT) -o $(NAME) $(MLXFLAGS)

$(LIBFT):
			@if [ ! -d "libft" ]; then git clone https://github.com/Pgorner/42-libft.git; fi
			@cd 42-libft && make && make clean
$(MLX42):
			@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
			@cd MLX42 && make

all :		$(NAME)

clean :
			$(RM) $(OBJS)

fclean :	clean
			@$(RM) $(NAME)
			@$(RM) ./42-libft
			@$(RM) ./MLX42

re :		fclean all

libft: $(LIBFT)
mlx: $(MLX42)

.PHONY: all clean fclean re
