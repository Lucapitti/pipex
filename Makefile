NAME = pipex
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = pipex_main.c utils.c
OBJ = $(patsubst %.c, %.o, $(SRCS))
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
INCL = -I./

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re